#include <gtest/gtest.h>
#include <unplayplay.hpp>

using namespace std::string_view_literals;

TEST(DecryptAndBindKey, Unit) {
    auto key = unplayplay::util::Key("01"sv);
    auto file_id = unplayplay::util::FileId("01"sv);

    auto bind_result = unplayplay::decrypt_and_bind_key(key, file_id);
    auto expected = unplayplay::util::Key("e32698dcafaba7529a223c8e34ec08cc"sv);
    EXPECT_EQ(bind_result, expected);
}
