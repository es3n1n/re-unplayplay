// src/export/re_unplayplay_export.h
#pragma once

#ifdef _WIN32
#define RE_UNPLAYPLAY_API __declspec(dllexport)
#else
#define RE_UNPLAYPLAY_API
#endif

extern "C" {
    // Function to decrypt a key
    RE_UNPLAYPLAY_API unsigned char* decrypt_key(const unsigned char* encrypted_key, int key_length, int* result_length);
    
    // Function to bind a key
    RE_UNPLAYPLAY_API unsigned char* bind_key(const unsigned char* decrypted_key, int key_length, const char* file_id, unsigned char* output_length);
    
    // Function to decrypt and bind a key
    RE_UNPLAYPLAY_API unsigned char* decrypt_and_bind_key(const unsigned char* encrypted_key, int key_length, const char* file_id, int* result_length);
    
    // Function to get a token
    RE_UNPLAYPLAY_API unsigned char* get_token(int* token_length);
    
    // Function to free memory allocated by the library
    RE_UNPLAYPLAY_API void free_memory(unsigned char* buffer);
}
