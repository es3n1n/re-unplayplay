#include <iomanip>
#include <iostream>

#include <unplayplay.hpp>

int main(const int argc, const char* argv[]) {
    if (argc < 2) {
        std::cerr << "usage: " << argv[0] << " {file_id} {encrypted_key}" << std::endl;
        return 1;
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
