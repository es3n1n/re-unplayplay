#include <gtest/gtest.h>
#include <unplayplay.hpp>

using namespace std::string_view_literals;

TEST(DecryptAndBindKey, Unit) {
    auto key = unplayplay::Key("01"sv);
    auto file_id = unplayplay::FileId("01"sv);

    auto bind_result = unplayplay::decrypt_and_bind_key(key, file_id);
    auto expected = unplayplay::Key("E6B81C1574CFE0E1A4D78D042E290D29"sv);
    EXPECT_EQ(bind_result, expected);
}
