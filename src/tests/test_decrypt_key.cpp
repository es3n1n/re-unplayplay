#include <gtest/gtest.h>
#include <unplayplay.hpp>

using namespace std::string_view_literals;

TEST(DecryptKey, Unit) {
    auto decrypted = unplayplay::decrypt_key(unplayplay::util::Key("01"sv));
    auto expected = unplayplay::util::Key("5d528f92bfb6a6b9dadf75e9f2bdff20"sv);

    EXPECT_EQ(decrypted, expected);
}
