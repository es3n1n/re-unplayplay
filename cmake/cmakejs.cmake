cmake_minimum_required(VERSION 3.12)

if(CMAKE_VERSION VERSION_GREATER_EQUAL 3.28)
    cmake_policy(SET CMP0153 NEW)
endif()

function(find_required_programs)
    find_program(CMAKEJS "cmake-js")
    find_program(NPM "npm")
    find_program(NODE "node")

    if(NOT NPM)
        message(FATAL_ERROR "[CMakeJS] NPM not found. This project requires Node.js")
    endif()

    if(WIN32)
        set(NPM_CMD "${NPM}.cmd" PARENT_SCOPE)
        set(CMAKEJS_CMD "${CMAKEJS}.cmd" PARENT_SCOPE)
    else()
        set(NPM_CMD "${NPM}" PARENT_SCOPE)
        set(CMAKEJS_CMD "${CMAKEJS}" PARENT_SCOPE)
    endif()
    set(NODE_CMD ${NODE} PARENT_SCOPE)
endfunction()

function(install_cmakejs_if_needed NPM_CMD)
    if(NOT CMAKEJS)
        message(STATUS "[CMakeJS] CMake.js not found, installing globally...")
        execute_process(
                COMMAND ${NPM_CMD} install -g cmake-js
                WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                RESULT_VARIABLE NPM_RESULT
                OUTPUT_VARIABLE NPM_OUTPUT
                ERROR_VARIABLE NPM_ERROR
        )
        if(NPM_RESULT EQUAL 0)
            message(STATUS "[CMakeJS] CMake.js installed successfully.")
            find_program(CMAKEJS "cmake-js")
            if(CMAKEJS)
                set(CMAKEJS_CMD ${CMAKEJS}${CMAKE_EXECUTABLE_SUFFIX} PARENT_SCOPE)
            else()
                message(FATAL_ERROR "[CMakeJS] CMake.js installed but not found in PATH")
            endif()
        else()
            message(FATAL_ERROR "[CMakeJS] Failed to install CMake.js: ${NPM_ERROR}")
        endif()
        message(VERBOSE ${NPM_OUTPUT})
    endif()
endfunction()

function(get_cmakejs_output CMAKEJS_CMD)
    set(CMAKEJS_ARGS print-configure)
    if(CMAKE_BUILD_TYPE STREQUAL "Debug")
        list(APPEND CMAKEJS_ARGS --debug)
    endif()

    execute_process(
            COMMAND ${CMAKEJS_CMD} ${CMAKEJS_ARGS}
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
            OUTPUT_VARIABLE CMAKE_JS_OUTPUT
            RESULT_VARIABLE CMAKEJS_RESULT
    )

    if(NOT CMAKEJS_RESULT EQUAL 0)
        message(FATAL_ERROR "[CMakeJS] Failed to get CMake.js output (cmd: ${CMAKEJS_CMD})")
    endif()

    set(CMAKE_JS_OUTPUT ${CMAKE_JS_OUTPUT} PARENT_SCOPE)
endfunction()

function(parse_cmakejs_output CMAKE_JS_OUTPUT)
    string(REGEX MATCH "-DCMAKE_JS_INC=[^']*" CMAKE_JS_INCLUDE_MATCH "${CMAKE_JS_OUTPUT}")
    string(REGEX MATCH "-DCMAKE_JS_LIB=[^']*" CMAKE_JS_LIB_MATCH "${CMAKE_JS_OUTPUT}")
    string(REGEX MATCH "-DCMAKE_RUNTIME_OUTPUT_DIRECTORY=[^']*" CMAKE_RUNTIME_OUTPUT_DIRECTORY_MATCH "${CMAKE_JS_OUTPUT}")
    string(REGEX MATCH "-DCMAKE_LIBRARY_OUTPUT_DIRECTORY=[^']*" CMAKE_LIBRARY_OUTPUT_DIRECTORY_MATCH "${CMAKE_JS_OUTPUT}")
    string(REGEX MATCH "-DCMAKE_JS_NODELIB_DEF=[^']*" CMAKE_JS_NODELIB_DEF_MATCH "${CMAKE_JS_OUTPUT}")
    string(REGEX MATCH "-DCMAKE_JS_NODELIB_TARGET=[^']*" CMAKE_JS_NODELIB_TARGET_MATCH "${CMAKE_JS_OUTPUT}")

    if(CMAKE_JS_INCLUDE_MATCH)
        string(REPLACE "-DCMAKE_JS_INC=" "" CMAKE_JS_INCLUDE "${CMAKE_JS_INCLUDE_MATCH}")
        # Define both _INC and _INCLUDE
        set(CMAKE_JS_INCLUDE "${CMAKE_JS_INCLUDE}" PARENT_SCOPE)
        set(CMAKE_JS_INC "${CMAKE_JS_INCLUDE}" PARENT_SCOPE)

        # Handle CMAKE_JS_LIB, which may be empty
        if(CMAKE_JS_LIB_MATCH)
            string(REPLACE "-DCMAKE_JS_LIB=" "" CMAKE_JS_LIB "${CMAKE_JS_LIB_MATCH}")
            set(CMAKE_JS_LIB "${CMAKE_JS_LIB}" PARENT_SCOPE)
        else()
            set(CMAKE_JS_LIB "" PARENT_SCOPE)
        endif()

        # Handle CMAKE_RUNTIME_OUTPUT_DIRECTORY, falling back to CMAKE_LIBRARY_OUTPUT_DIRECTORY if needed
        if(CMAKE_RUNTIME_OUTPUT_DIRECTORY_MATCH)
            string(REPLACE "-DCMAKE_RUNTIME_OUTPUT_DIRECTORY=" "" CMAKE_OUTPUT_DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY_MATCH}")
        elseif(CMAKE_LIBRARY_OUTPUT_DIRECTORY_MATCH)
            string(REPLACE "-DCMAKE_LIBRARY_OUTPUT_DIRECTORY=" "" CMAKE_OUTPUT_DIRECTORY "${CMAKE_LIBRARY_OUTPUT_DIRECTORY_MATCH}")
        else()
            set(CMAKE_OUTPUT_DIRECTORY "" PARENT_SCOPE)
        endif()

        # Set CMAKE_RUNTIME_OUTPUT_DIRECTORY/CMAKE_LIBRARY_OUTPUT_DIRECTORY
        if(DEFINED CMAKE_OUTPUT_DIRECTORY)
            set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_OUTPUT_DIRECTORY}" PARENT_SCOPE)
            set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_OUTPUT_DIRECTORY}" PARENT_SCOPE)
        endif()

        # Set CMAKE_JS_NODELIB_DEF
        if(CMAKE_JS_NODELIB_DEF_MATCH)
            string(REPLACE "-DCMAKE_JS_NODELIB_DEF=" "" CMAKE_JS_NODELIB_DEF "${CMAKE_JS_NODELIB_DEF_MATCH}")
            string(REGEX REPLACE "[\r\n\"]" "" CMAKE_JS_NODELIB_DEF ${CMAKE_JS_NODELIB_DEF})
        else()
            set(CMAKE_JS_NODELIB_DEF "")
        endif()

        # Set CMAKE_JS_NODELIB_TARGET
        if(CMAKE_JS_NODELIB_TARGET_MATCH)
            string(REPLACE "-DCMAKE_JS_NODELIB_TARGET=" "" CMAKE_JS_NODELIB_TARGET "${CMAKE_JS_NODELIB_TARGET_MATCH}")
            string(REGEX REPLACE "[\r\n\"]" "" CMAKE_JS_NODELIB_TARGET ${CMAKE_JS_NODELIB_TARGET})
        else()
            set(CMAKE_JS_NODELIB_TARGET "")
        endif()

        # On msvc we have to build node.lib
        if(MSVC AND CMAKE_JS_NODELIB_TARGET AND CMAKE_JS_NODELIB_DEF AND NOT EXISTS "${CMAKE_JS_NODELIB_TARGET}")
            execute_process(
                    COMMAND ${CMAKE_AR} /def:${CMAKE_JS_NODELIB_DEF} /out:${CMAKE_JS_NODELIB_TARGET} ${CMAKE_STATIC_LINKER_FLAGS}
                    RESULT_VARIABLE CMAKE_AR_RESULT
            )

            if(NOT CMAKE_AR_RESULT EQUAL 0)
                message(FATAL_ERROR "[CMakeJS] Failed to generate node.lib at ${CMAKE_JS_NODELIB_TARGET}")
            endif()

            message(VERBOSE "[CMakeJS] Generated node.lib")
        endif()
    else()
        message(FATAL_ERROR "[CMakeJS] Failed to parse CMake.js output: CMAKE_JS_INC not found")
    endif()
endfunction()

function(get_node_addon_api_include NODE_CMD)
    execute_process(
            COMMAND "${NODE_CMD}" -p "require('node-addon-api').include"
            WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
            OUTPUT_VARIABLE NODE_ADDON_API_INCLUDE
            RESULT_VARIABLE NODE_RESULT
    )

    if(NOT NODE_RESULT EQUAL 0)
        message(FATAL_ERROR "[CMakeJS] Failed to get node-addon-api include path")
    endif()

    string(REGEX REPLACE "[\r\n\"]" "" NODE_ADDON_API_INCLUDE ${NODE_ADDON_API_INCLUDE})

    # Define both inc and include
    set(NODE_ADDON_API_INCLUDE ${NODE_ADDON_API_INCLUDE} PARENT_SCOPE)
    set(NODE_ADDON_API_INC ${NODE_ADDON_API_INCLUDE} PARENT_SCOPE)
endfunction()

macro(setup_cmakejs)
    message(STATUS "[CMakeJS] Setting up variables.")

    find_required_programs()
    install_cmakejs_if_needed(${NPM_CMD})
    get_cmakejs_output(${CMAKEJS_CMD})
    parse_cmakejs_output("${CMAKE_JS_OUTPUT}")
    get_node_addon_api_include(${NODE_CMD})

    message(STATUS "[CMakeJS] Set up variables.")
    message(VERBOSE "[CMakeJS] CMAKE_JS_INCLUDE: ${CMAKE_JS_INCLUDE}")
    message(VERBOSE "[CMakeJS] CMAKE_JS_LIB: ${CMAKE_JS_LIB}")
    message(VERBOSE "[CMakeJS] CMAKE_RUNTIME_OUTPUT_DIRECTORY: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
    message(VERBOSE "[CMakeJS] NODE_ADDON_API_INCLUDE: ${NODE_ADDON_API_INCLUDE}")
endmacro()

setup_cmakejs()
