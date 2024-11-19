#include "unplayplay.hpp"
#include <iomanip>
#include <iostream>
#include <string>

namespace {
    template <std::size_t N>
    void to_stdout(const unplayplay::util::ByteBuffer<N>& value) {
        for (std::size_t i = 0; i < value.size(); ++i) {
            std::cout << std::setw(2) << std::setfill('0') << std::hex << static_cast<int>(value[i]);
        }
        std::cout << std::endl;
    }

    void usage(const char* argv[]) {
        std::cerr << "Usage: " << argv[0] << " <command> [args...]" << std::endl
                  << "Commands:" << std::endl
                  << "  token                          Display linked token" << std::endl
                  << "  <file_id_hex> <enc_key_hex>    Decrypt and bind key for specified file" << std::endl;
    }
} // namespace

int main(const int argc, const char* argv[]) {
    if (argc == 2 && std::string_view{argv[1]} == "token") {
        to_stdout(unplayplay::get_token());
        return 0;
    }

    if (argc != 3) {
        usage(argv);
        return 1;
    }

    const auto file_id = unplayplay::FileId(argv[1]);
    const auto encrypted_key = unplayplay::Key(argv[2]);
    const auto result = unplayplay::decrypt_and_bind_key(encrypted_key, file_id);

    to_stdout(result);
    return 0;
}
