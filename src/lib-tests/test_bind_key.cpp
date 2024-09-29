#include <gtest/gtest.h>
#include <unplayplay.hpp>

using namespace std::string_view_literals;

TEST(BindKey, Unit) {
    auto decrypted = unplayplay::decrypt_key(unplayplay::util::Key("01"sv));
    auto file_id = unplayplay::util::FileId("01"sv);

    auto bind_result = unplayplay::bind_key(decrypted, file_id);
    auto expected = unplayplay::util::Key("E32698DCAFABA7529A223C8E34EC08CC"sv);
    EXPECT_EQ(bind_result, expected);
}
