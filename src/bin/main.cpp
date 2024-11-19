#include <iomanip>
#include <iostream>
#include <string>
#include "unplayplay.hpp"

int main(const int argc, const char* argv[]) {
    if (argc < 2) {
        std::cerr << "usage: " << argv[0] << " {file_id} {encrypted_key}" << std::endl;
        return 1;
    }

    std::string arg1(argv[1]);
    if (arg1 == "token") {
        const auto token = unplayplay::get_token();

        for (std::size_t i = 0; i < token.size(); ++i) {
            std::cout << std::setw(2) << std::setfill('0') << std::hex
                      << static_cast<int>(token[i]);
        }
        std::cout << std::endl;

        return 0;
    }

    const auto file_id = unplayplay::FileId(argv[1]);
    const auto encrypted_key = unplayplay::Key(argv[2]);
    const auto result = unplayplay::decrypt_and_bind_key(encrypted_key, file_id);

    for (std::size_t i = 0; i < result.size(); ++i) {
        std::cout << std::setw(2) << std::setfill('0') << std::hex << static_cast<int>(result[i]);
    }
    std::cout << std::endl;

    return 0;
}
