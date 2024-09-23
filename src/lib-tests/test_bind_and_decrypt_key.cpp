#include <gtest/gtest.h>
#include <unplayplay.hpp>

using namespace std::string_view_literals;

TEST(DecryptAndBindKey, Unit) {
    auto key = unplayplay::util::Key("01"sv);
    auto file_id = unplayplay::util::FileId("01"sv);

    auto bind_result = unplayplay::decrypt_and_bind_key(key, file_id);
    auto expected = unplayplay::util::Key("f3a37e28d15bc5e8151d413eb36a59b5"sv);
    EXPECT_EQ(bind_result, expected);
}
