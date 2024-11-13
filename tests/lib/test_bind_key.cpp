#include <gtest/gtest.h>
#include <unplayplay.hpp>

using namespace std::string_view_literals;

TEST(BindKey, Unit) {
    auto decrypted = unplayplay::decrypt_key(unplayplay::Key("01"sv));
    auto file_id = unplayplay::FileId("01"sv);

    auto bind_result = unplayplay::bind_key(decrypted, file_id);
    auto expected = unplayplay::Key("7EE4480B767DD92A03E90A7FC1FF4099"sv);
    EXPECT_EQ(bind_result, expected);
}
