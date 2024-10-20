// src/export/re_unplayplay_export.cpp
#include "re_unplayplay_export.h"
#include <unplayplay.hpp> // Adjust the path as necessary
#include <cstring>       // For string and memory operations

using namespace unplayplay;

// Function to decrypt a key
unsigned char* decrypt_key(const unsigned char* encrypted_key, int key_length, int* result_length) {
    try {
        Key encryptedKey(encrypted_key, key_length);
        auto decrypted = decrypt_key(encryptedKey);
        
        // Allocate memory for the result
        *result_length = static_cast<int>(decrypted.size());
        unsigned char* buffer = new unsigned char[*result_length];
        std::memcpy(buffer, decrypted.data(), *result_length);
        return buffer;
    } catch (...) {
        *result_length = 0;
        return nullptr;
    }
}

// Function to bind a key
unsigned char* bind_key(const unsigned char* decrypted_key, int key_length, const char* file_id, unsigned char* output_length) {
    try {
        Key decryptedKey(decrypted_key, key_length);
        FileId fid(file_id);
        auto bound = bind_key(decryptedKey, fid);
        
        // Allocate memory for the result
        *output_length = static_cast<unsigned char>(bound.size());
        unsigned char* buffer = new unsigned char[*output_length];
        std::memcpy(buffer, bound.data(), *output_length);
        return buffer;
    } catch (...) {
        *output_length = 0;
        return nullptr;
    }
}

// Function to decrypt and bind a key
unsigned char* decrypt_and_bind_key(const unsigned char* encrypted_key, int key_length, const char* file_id, int* result_length) {
    try {
        Key encryptedKey(encrypted_key, key_length);
        FileId fid(file_id);
        auto decryptedBound = decrypt_and_bind_key(encryptedKey, fid);
        
        // Allocate memory for the result
        *result_length = static_cast<int>(decryptedBound.size());
        unsigned char* buffer = new unsigned char[*result_length];
        std::memcpy(buffer, decryptedBound.data(), *result_length);
        return buffer;
    } catch (...) {
        *result_length = 0;
        return nullptr;
    }
}

// Function to get a token
unsigned char* get_token(int* token_length) {
    try {
        auto token = get_token();
        
        // Allocate memory for the token
        *token_length = static_cast<int>(token.size());
        unsigned char* buffer = new unsigned char[*token_length];
        std::memcpy(buffer, token.data(), *token_length);
        return buffer;
    } catch (...) {
        *token_length = 0;
        return nullptr;
    }
}

// Function to free memory allocated by the library
void free_memory(unsigned char* buffer) {
    delete[] buffer;
}
