#include <array>
#include <napi.h>
#include <string>
#include <unplayplay.hpp>

namespace unpp = unplayplay;

namespace impl {
    using NByteArray = Napi::Buffer<std::uint8_t>;

    static unpp::Key key_from_buffer(const Napi::Buffer<uint8_t>& buffer) {
        return unpp::Key(buffer.Data(), buffer.Length());
    }

    template <size_t N>
    static NByteArray to_buffer(Napi::Env env, unpp::util::ByteBuffer<N> key) {
        return Napi::Buffer<uint8_t>::Copy(env, key.data(), key.size());
    }

    static NByteArray decrypt_key(const Napi::CallbackInfo& info) {
        Napi::Env env = info.Env();

        if (info.Length() < 1 || !info[0].IsBuffer()) {
            throw Napi::TypeError::New(env, "Expected a Buffer");
        }

        auto encrypted_key = key_from_buffer(info[0].As<Napi::Buffer<uint8_t>>());
        auto result = unpp::decrypt_key(encrypted_key);
        return to_buffer(env, result);
    }

    static NByteArray bind_key(const Napi::CallbackInfo& info) {
        Napi::Env env = info.Env();

        if (info.Length() < 2 || !info[0].IsBuffer() || !info[1].IsString()) {
            throw Napi::TypeError::New(env, "Wrong number of arguments or invalid types");
        }

        auto decrypted_key = key_from_buffer(info[0].As<Napi::Buffer<uint8_t>>());
        std::string file_id_view = info[1].As<Napi::String>().Utf8Value();
        if (!unpp::util::detail::validate_bytes_view_size(file_id_view.size())) {
            throw Napi::TypeError::New(env, "Invalid size of file_id");
        }

        const auto file_id = unpp::FileId(file_id_view);

        auto result = unpp::bind_key(decrypted_key, file_id);
        return to_buffer(env, result);
    }

    static NByteArray decrypt_and_bind_key(const Napi::CallbackInfo& info) {
        Napi::Env env = info.Env();

        if (info.Length() < 2 || !info[0].IsBuffer() || !info[1].IsString()) {
            throw Napi::TypeError::New(env, "Wrong number of arguments or invalid types");
        }

        auto encrypted_key = key_from_buffer(info[0].As<Napi::Buffer<uint8_t>>());
        std::string file_id_view = info[1].As<Napi::String>().Utf8Value();
        if (!unpp::util::detail::validate_bytes_view_size(file_id_view.size())) {
            throw Napi::TypeError::New(env, "Invalid size of file_id");
        }

        const auto file_id = unpp::FileId(file_id_view);
        auto result = unpp::decrypt_and_bind_key(encrypted_key, file_id);
        return to_buffer(env, result);
    }

    static NByteArray get_token(const Napi::CallbackInfo& info) {
        return to_buffer(info.Env(), unpp::get_token());
    }
} // namespace impl

static Napi::Object startup(Napi::Env env, Napi::Object exports) {
    exports.Set(Napi::String::New(env, "decryptKey"), Napi::Function::New(env, impl::decrypt_key));
    exports.Set(Napi::String::New(env, "bindKey"), Napi::Function::New(env, impl::bind_key));
    exports.Set(Napi::String::New(env, "decryptAndBindKey"), Napi::Function::New(env, impl::decrypt_and_bind_key));
    exports.Set(Napi::String::New(env, "getToken"), Napi::Function::New(env, impl::get_token));
    return exports;
}

NODE_API_MODULE(re_unplayplay, startup)
