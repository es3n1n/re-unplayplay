# This file is automatically generated from cmake.toml - DO NOT EDIT
# See https://github.com/build-cpp/cmkr for more information

cmake_minimum_required(VERSION 3.15)

if(CMAKE_SOURCE_DIR STREQUAL CMAKE_BINARY_DIR)
	message(FATAL_ERROR "In-tree builds are not supported. Run CMake from a separate directory: cmake -B build")
endif()

set(CMKR_ROOT_PROJECT OFF)
if(CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
	set(CMKR_ROOT_PROJECT ON)

	# Bootstrap cmkr and automatically regenerate CMakeLists.txt
	include("cmake/cmkr.cmake" OPTIONAL RESULT_VARIABLE CMKR_INCLUDE_RESULT)
	if(CMKR_INCLUDE_RESULT)
		cmkr()
	endif()

	# Enable folder support
	set_property(GLOBAL PROPERTY USE_FOLDERS ON)

	# Create a configure-time dependency on cmake.toml to improve IDE support
	configure_file(cmake.toml cmake.toml COPYONLY)
endif()

# Enable support for MSVC_RUNTIME_LIBRARY
cmake_policy(SET CMP0091 NEW)
if(NOT DEFINED CMAKE_MSVC_RUNTIME_LIBRARY)
	set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif()

# Options
option(RE_UNPP_BUILD_TESTS "" OFF)
option(RE_UNPP_BUILD_PYTHON "" OFF)
option(RE_UNPP_BUILD_JS "" OFF)

project(re-unplayplay
	LANGUAGES
		CXX
)

include(FetchContent)

# Fix warnings about DOWNLOAD_EXTRACT_TIMESTAMP
if(POLICY CMP0135)
	cmake_policy(SET CMP0135 NEW)
endif()
if(RE_UNPP_BUILD_TESTS) # re-unpp-build-tests
	message(STATUS "Fetching GTest (v1.15.2)...")
	FetchContent_Declare(GTest
		GIT_REPOSITORY
			"https://github.com/google/googletest"
		GIT_TAG
			v1.15.2
	)
	FetchContent_MakeAvailable(GTest)

endif()
if(RE_UNPP_BUILD_PYTHON) # re-unpp-build-python
	message(STATUS "Fetching pybind11 (v2.13.6)...")
	FetchContent_Declare(pybind11
		GIT_REPOSITORY
			"https://github.com/pybind/pybind11.git"
		GIT_TAG
			v2.13.6
	)
	FetchContent_MakeAvailable(pybind11)

endif()
# Target: re-unplayplay
set(re-unplayplay_SOURCES
	cmake.toml
	"src/lib/reversals/bind_key.cpp"
	"src/lib/reversals/decrypt_key.cpp"
)

add_library(re-unplayplay)

target_sources(re-unplayplay PRIVATE ${re-unplayplay_SOURCES})
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${re-unplayplay_SOURCES})

add_library(unplayplay::lib ALIAS re-unplayplay)
target_compile_definitions(re-unplayplay PUBLIC
	NOMINMAX
)

target_compile_features(re-unplayplay PUBLIC
	cxx_std_17
)

if(MSVC) # msvc
	target_compile_options(re-unplayplay PUBLIC
		"/MP"
	)
endif()

if(CMAKE_SYSTEM_NAME MATCHES "Linux") # linux
	target_compile_options(re-unplayplay PUBLIC
		-fPIC
	)
endif()

target_include_directories(re-unplayplay PUBLIC
	"src/lib/"
)

# Target: re-unplayplay-cli
set(re-unplayplay-cli_SOURCES
	cmake.toml
	"src/bin/main.cpp"
)

add_executable(re-unplayplay-cli)

target_sources(re-unplayplay-cli PRIVATE ${re-unplayplay-cli_SOURCES})
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${re-unplayplay-cli_SOURCES})

target_link_libraries(re-unplayplay-cli PRIVATE
	unplayplay::lib
)

get_directory_property(CMKR_VS_STARTUP_PROJECT DIRECTORY ${PROJECT_SOURCE_DIR} DEFINITION VS_STARTUP_PROJECT)
if(NOT CMKR_VS_STARTUP_PROJECT)
	set_property(DIRECTORY ${PROJECT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT re-unplayplay-cli)
endif()

# Target: re-unplayplay-tests
if(RE_UNPP_BUILD_TESTS) # re-unpp-build-tests
	set(re-unplayplay-tests_SOURCES
		cmake.toml
		"tests/lib/test_bind_and_decrypt_key.cpp"
		"tests/lib/test_bind_key.cpp"
		"tests/lib/test_decrypt_key.cpp"
	)

	add_executable(re-unplayplay-tests)

	target_sources(re-unplayplay-tests PRIVATE ${re-unplayplay-tests_SOURCES})
	source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${re-unplayplay-tests_SOURCES})

	target_include_directories(re-unplayplay-tests PRIVATE
		"tests/lib/"
	)

	target_link_libraries(re-unplayplay-tests PRIVATE
		unplayplay::lib
		GTest::gtest_main
	)

	get_directory_property(CMKR_VS_STARTUP_PROJECT DIRECTORY ${PROJECT_SOURCE_DIR} DEFINITION VS_STARTUP_PROJECT)
	if(NOT CMKR_VS_STARTUP_PROJECT)
		set_property(DIRECTORY ${PROJECT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT re-unplayplay-tests)
	endif()

endif()
# Target: re-unplayplay-python
if(RE_UNPP_BUILD_PYTHON) # re-unpp-build-python
	set(re-unplayplay-python_SOURCES
		cmake.toml
		"src/python/main.cpp"
	)

	pybind11_add_module(re-unplayplay-python ${re-unplayplay-python_SOURCES})
	source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${re-unplayplay-python_SOURCES})

	target_link_libraries(re-unplayplay-python PUBLIC
		unplayplay::lib
	)

	set(CMKR_TARGET re-unplayplay-python)
	set_property(TARGET re-unplayplay-python PROPERTY OUTPUT_NAME _re_unplayplay)
	install(TARGETS re-unplayplay-python LIBRARY DESTINATION .)

endif()
# Target: node-api
if(RE_UNPP_BUILD_JS) # re-unpp-build-js
	set(CMKR_TARGET node-api)
	include("cmake/cmakejs.cmake")

	add_library(node-api INTERFACE)

	target_compile_definitions(node-api INTERFACE
		NAPI_VERSION=7
	)

	target_include_directories(node-api INTERFACE
		${CMAKE_JS_INC}
		${NODE_ADDON_API_INCLUDE}
	)

	target_link_libraries(node-api INTERFACE
		${CMAKE_JS_LIB}
	)

	target_sources(node-api INTERFACE ${CMAKE_JS_SRC})

endif()
# Target: re-unplayplay-js
if(RE_UNPP_BUILD_JS) # re-unpp-build-js
	set(re-unplayplay-js_SOURCES
		cmake.toml
		"src/js/main.cpp"
	)

	add_library(re-unplayplay-js SHARED)

	target_sources(re-unplayplay-js PRIVATE ${re-unplayplay-js_SOURCES})
	source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${re-unplayplay-js_SOURCES})

	target_link_libraries(re-unplayplay-js PUBLIC
		node-api
		unplayplay::lib
	)

	set(CMKR_TARGET re-unplayplay-js)
	set_target_properties(re-unplayplay-js PROPERTIES
	    PREFIX ""
	    SUFFIX ".node"
	    LINKER_LANGUAGE CXX
	)
	install(TARGETS re-unplayplay-js LIBRARY DESTINATION .)

endif()
