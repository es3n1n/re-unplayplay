#pragma once
#include "constants.hpp"
#include "util.hpp"

namespace unplayplay {
    [[nodiscard]] util::Key decrypt_key(util::Key key_basis) noexcept;
    [[nodiscard]] util::Key bind_key(util::Key decrypted_key, util::FileId file_id) noexcept;

    [[nodiscard]] inline util::Token get_token() noexcept {
        return util::Token{detail::kPlayPlayToken.data()};
    }

    [[nodiscard]] inline util::Key decrypt_and_bind_key(util::Key key_basis, util::FileId file_id) noexcept {
        const auto decrypted_key = decrypt_key(key_basis);
        return bind_key(decrypted_key, file_id);
    }
} // namespace unplayplay
