#pragma once
#include "util.hpp"

namespace unplayplay {
    [[nodiscard]] util::Key decrypt_key(util::Key key_basis) noexcept;
    [[nodiscard]] util::Key bind_key(util::Key decrypted_key, util::FileId file_id) noexcept;
} // namespace unplayplay
