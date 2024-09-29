#include <pybind11/iostream.h>
#include <pybind11/pybind11.h>
#include <string>
#include <unplayplay.hpp>

namespace py = pybind11;
namespace unpp = unplayplay;

namespace impl {
    static unpp::util::Key key_from_bytes(const py::bytes& key) {
        const auto view = static_cast<std::string_view>(key);
        return unpp::util::Key(reinterpret_cast<const std::uint8_t*>(view.data()), view.size());
    }

    template <size_t N>
    static py::bytes to_bytes(unpp::util::ByteBuffer<N> key) {
        return py::bytes(reinterpret_cast<char*>(key.data()), key.size());
    }

    [[nodiscard]] py::bytes decrypt_key(const py::bytes& encrypted_key) {
        auto result = unpp::decrypt_key(key_from_bytes(encrypted_key));
        return to_bytes(result);
    }

    [[nodiscard]] py::bytes bind_key(const py::bytes& decrypted_key, const std::string& file_id_view) {
        const auto key = key_from_bytes(decrypted_key);
        const auto file_id = unpp::util::FileId(file_id_view);

        auto result = unpp::bind_key(key, file_id);
        return to_bytes(result);
    }

    [[nodiscard]] py::bytes decrypt_and_bind_key(const py::bytes& encrypted_key, const std::string& file_id_view) {
        const auto key = key_from_bytes(encrypted_key);
        const auto file_id = unpp::util::FileId(file_id_view);

        auto decrypted = unpp::decrypt_key(key);
        auto result = unpp::bind_key(decrypted, file_id);
        return to_bytes(result);
    }

    [[nodiscard]] py::bytes get_token() {
        return to_bytes(unpp::get_token());
    }
} // namespace impl

/// Intentionally re_unplayplay and not re_unplayplay_python,
/// because we're renaming it later on in setup.py
PYBIND11_MODULE(_re_unplayplay, m) {
    m.def("decrypt_key", &impl::decrypt_key);
    m.def("bind_key", &impl::bind_key);
    m.def("decrypt_and_bind_key", &impl::decrypt_and_bind_key);
    m.def("get_token", &impl::get_token);
}