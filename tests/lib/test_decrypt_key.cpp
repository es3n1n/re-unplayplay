#include <gtest/gtest.h>
#include <unplayplay.hpp>

using namespace std::string_view_literals;

using Param = std::tuple<std::string_view, std::string_view>;
class DecryptKeyFixture : public testing::TestWithParam<Param> { };

TEST_P(DecryptKeyFixture, Unit) {
    const auto [key_basis, expected_view] = GetParam();

    auto decrypted = unplayplay::decrypt_key(unplayplay::Key(key_basis));
    auto expected = unplayplay::Key(expected_view);

    EXPECT_EQ(decrypted, expected);
}

INSTANTIATE_TEST_SUITE_P( //
    DecryptKey, DecryptKeyFixture,
    ::testing::Values( //
        Param{"f2dec119e3a11e0c59469557c97bf17e"sv, "1613b9e4c6ee74c9abdd60401391f0f4"sv}, // auto-generated
        Param{"71d2f1c203c9e7f6fe5454ade21c1feb"sv, "3b031a8a537b4b1c32383f7793e45919"sv}, // auto-generated
        Param{"4551058183e4c90fbf1f66f06cd1b283"sv, "ab757ad979e2ec2316e565b647121515"sv}, // auto-generated
        Param{"568708a5e5344fa6b5928d8e9a3faf66"sv, "5a1ac46fd0d91338cdd005c02bcb3a17"sv}, // auto-generated
        Param{"3b4fbf1f1979a83d827e17e7531fb646"sv, "30068f7399f5b7dec3968bdaed5e74d7"sv}, // auto-generated
        Param{"060497c736d8e6b69d579402c8c1d0cf"sv, "613628e51b4243992b3203b3f3c2bba9"sv}, // auto-generated
        Param{"84280e85c0c55a84e0063869848e0803"sv, "5b9d3680c241b779ff4fb39c3db22bb8"sv}, // auto-generated
        Param{"02e17dfc16000282f1502f7d50e6fc27"sv, "b368b010b848519d381f00ccbd51124f"sv}, // auto-generated
        Param{"fa6922c973ef17653ec0416b81781b01"sv, "1e452318e61e9df78cf894e8eef7fb8c"sv}, // auto-generated
        Param{"23e5f7d816bf6826d9e9e72422c62e8b"sv, "a3301e63edb994110cd88899dfaab98a"sv}, // auto-generated
        Param{"b76eef03769b1caecc4dc532802e64f2"sv, "98eafcb077411e743425f2f7dbdb9c4e"sv}, // auto-generated
        Param{"64d9323cb5a4a11dfc6d856204739fce"sv, "526b566ef6c0e23e43a8ee623555bced"sv}, // auto-generated
        Param{"5c26205d6de61338cce947fc3eb8ab60"sv, "b54323ba28cc8fc4c28902f28b49a934"sv}, // auto-generated
        Param{"05a33c559a9a655aa991c0f850721d08"sv, "8fd7a510beeeda1ba48a54c3c027327f"sv}, // auto-generated
        Param{"b49420f4733361fc98c3d05094e84f3a"sv, "09b983d16aa9147275d0c093c1e8bd69"sv}, // auto-generated
        Param{"0b0d5a07fb4b7eac52fd930f2bc87323"sv, "157397b771a5942dbc100ee05e55311e"sv}, // auto-generated
        Param{"7cb55430661d45b0af907a4f997993d1"sv, "5b6c1eb72a0d29f7488b9eea87620656"sv}, // auto-generated
        Param{"b7bff85afeceeb493f7d6efb41276bb4"sv, "6930745e44e1ee53f587441b155bd1a6"sv}, // auto-generated
        Param{"4dbaaea8258a2e51355b87c5d2f3f42d"sv, "d0d7e733055d4f56e166bf4c159bd69c"sv}, // auto-generated
        Param{"c8011e140066eb5e61523c5a3c74b86f"sv, "26b2d7d4f35ba8aea71a5d54989659ca"sv}, // auto-generated
        Param{"12670ca19edfa10609af4924930d0447"sv, "ce7f7f77f1e687a2158009635f653705"sv}, // auto-generated
        Param{"10bd776e8e4f51c1c46c5e1bed77c71e"sv, "682d4a3db28f73fb7f362dbac37b3aac"sv}, // auto-generated
        Param{"22d080771c75615ce3cec9df20bca855"sv, "cba99e84f97d86a0dc5ac15e2289c7d9"sv}, // auto-generated
        Param{"f00cb91c96a79ddaea8623d630d7223e"sv, "a5babe508dd2352d33ae8d26cf451dd8"sv}, // auto-generated
        Param{"05686be512bbe9c5927b5623bd03b5bc"sv, "bd22634241327ec5fe61c0d6d46b383e"sv}, // auto-generated
        Param{"7cdaa6a158b8f92f5ca1cf80669f7f8c"sv, "2968831e57b5564ed087cea69c2b176a"sv}, // auto-generated
        Param{"bd8cb5f36b8de2a2f6696f9143dfcccc"sv, "4789a4d625caaa85067ac5a4df998964"sv}, // auto-generated
        Param{"caed40d561daa8ef2b832a1cebcc9d52"sv, "9a0166e48e609788e2c36588503a0521"sv}, // auto-generated
        Param{"b6e1bbf60d96c88f9e1339cc2bd0c5b2"sv, "1b73afb6f659dc7c599c8127b412df71"sv}, // auto-generated
        Param{"537c7e1e2675824beeda8c56b4352576"sv, "b7c30df7a8fd194abc983dcd52635f04"sv}, // auto-generated
        Param{"580c18a80e2ed8eec2c1690c010288de"sv, "ef7293b155fb17c079158ae56ba22c4b"sv}, // auto-generated
        Param{"2469bbf1d8f254914282ae4cceedb59f"sv, "43982ec916cebbf340c62c6571217913"sv}, // auto-generated
        Param{"ce452fd0e54c636bec837e879b37c8f2"sv, "3084c3af6b4f8ee8cdd107325e42881e"sv}, // auto-generated
        Param{"46b7bcd184ee38d6f481c05b8c0bbcbc"sv, "5ef3b972ce9e25aae491a718812a3dad"sv}, // auto-generated
        Param{"e8c59420ccad549de02209664a522412"sv, "24f0cf4d9bdf78418b6abd2038ffc277"sv}, // auto-generated
        Param{"25bcd11b6aa640c628742c03799e2597"sv, "90c8544f15f44781712ba8a5c25ed089"sv}, // auto-generated
        Param{"b71ce165700b42a4e5ce3bf649324e47"sv, "bf23accc47f73ddc765fd64675a78f47"sv}, // auto-generated
        Param{"10e5d2e39288d374b35e65837ba6cd07"sv, "4cfcd37d25674406f5418afe036796d0"sv}, // auto-generated
        Param{"913e2e04424a1398255f743e145b1d14"sv, "c9178e3ab08bfa3e0c1dd419d7733b59"sv}, // auto-generated
        Param{"6f33165368cff395b0948dca0dce68bd"sv, "0cf69e96891c281c88a7f338dba45870"sv}, // auto-generated
        Param{"6383346e54816c3fc9c64a652c7a6f91"sv, "bfb6315ae617b3083a552b7ebe18d470"sv}, // auto-generated
        Param{"aadd8b3aa84947e56b844f8ca59cb29d"sv, "f638b32668d63f6d58cd1472a8b694fd"sv}, // auto-generated
        Param{"bdba476eb705c8cf111b044955801e40"sv, "5cfb5241067907903705fea278ca3ffa"sv}, // auto-generated
        Param{"2bfa58dd593aadf550eca0b279ec8c09"sv, "d9dea33952471f8edc7cd5ee3f44e907"sv}, // auto-generated
        Param{"23d7d6e147ec5e552d644dc3cfcf2856"sv, "d4ea40b1c6167a666770f614f494c34b"sv}, // auto-generated
        Param{"4b41effa38a24fedd3d12cf4e9708a12"sv, "8bd9e9ccde945293c7dca1d9facda690"sv}, // auto-generated
        Param{"f8b3d40c07de0c6f0efb2035838e6c89"sv, "aba0c7ce131444b0b757f3a7fad18ebd"sv}, // auto-generated
        Param{"bf1f3def1e5dc2f9793379cc911a8e2e"sv, "bf644944bc312807af74c96799e474ec"sv}, // auto-generated
        Param{"b16122fda642add53040c73c048f2bce"sv, "d73262ff3892b3b4c93536c9632646e3"sv}, // auto-generated
        Param{"ec27dfb6934fcc327a572e95890071e3"sv, "f835f6dd29d35463c0866fd737d4a0a7"sv}, // auto-generated
        Param{"7ccc46e85f9ecdd8954bc287367d13cb"sv, "376cfaefd7ccb6b9fb4b9c7e55320af3"sv}, // auto-generated
        Param{"70b5690defd981aad828dad65f7a4327"sv, "6432d759a467a40f048d8a6aca2d0c7f"sv}, // auto-generated
        Param{"fef82f326aa1bf6370513876eda4f4b8"sv, "bc891920b7d1d40719f12a86df1d39e4"sv}, // auto-generated
        Param{"eb6875fdaf5c4c49808ee09e5c90bb73"sv, "9ad91743dd235f5033d66890225d6960"sv}, // auto-generated
        Param{"a2ab6b9cebca34efc4dcd505086b2f4a"sv, "bd311a8f9c8b9132e6885ca4e1922240"sv}, // auto-generated
        Param{"9730cb9ccb708cd4a0970f84286a0c4c"sv, "e37dcee146cc17b634c0aaa31223e720"sv}, // auto-generated
        Param{"be3b4bd96779fc7254cdf459c2b75a25"sv, "e7e5dbb041ebf417570dcf6e3b43eac1"sv}, // auto-generated
        Param{"54d78091591c40e691a5328f3121d058"sv, "837ad4d832d6e4e2fe18a56c17f929b9"sv}, // auto-generated
        Param{"79ab77136c42ee4bb23f7f3dc5b92621"sv, "14f4ba428c0cb9ddee147ba453a59aa9"sv}, // auto-generated
        Param{"a5758df274816b12504259c525031337"sv, "e48c80611a306afb0c1ff1dbaf05e7ee"sv}, // auto-generated
        Param{"62707bf0c2098bba554d8f92743d4ed8"sv, "e09905252541814019d9b8109dfb5ec0"sv}, // auto-generated
        Param{"abc8757a8c73a8fc5af6fc5f615c0923"sv, "fe774da809119e054b51c578bc6ba839"sv}, // auto-generated
        Param{"265583234ff25075f1ee05f64a6073a0"sv, "26ddc887c0f8d4f7a101fb3bbf9cfae5"sv}, // auto-generated
        Param{"ad0a0d901e11019b029d1003b7c67960"sv, "6fc9c1e5f2622ea3835dd69ee25c9516"sv}, // auto-generated
        Param{"7f30844f78dc11eb4e3a844a3180bd5f"sv, "d7388ed13644799f2eeed038b3ed7b50"sv}, // auto-generated
        Param{"af21d7e7868d696e6cda93b8e016524e"sv, "992c49bee723f7a9a5f96ef75500ad77"sv}, // auto-generated
        Param{"217e7d49e0684516c1fcfc6b39191722"sv, "6b3354489051d62fa97cf092dc37a387"sv}, // auto-generated
        Param{"353b1954b9c5a5d9d899374e75a0f3c8"sv, "48c2427c6de4db6dfdb34d06583ae0c1"sv}, // auto-generated
        Param{"4db1c06aabe42da13285defb26aa28c0"sv, "f1f970a5f2575245bcbe8d70565f04c0"sv}, // auto-generated
        Param{"b2fccc869f5176540fa173f4471cb541"sv, "ff680cbecaf6f66bfcf618fee03e7b25"sv}, // auto-generated
        Param{"78647d4cfdcdce3daf87a1530f4f7b5c"sv, "08f9a8a7afb476cd1d1ce140950637aa"sv}, // auto-generated
        Param{"640b03150e0a174eda0ed7b4967e71ef"sv, "7422f632c8f240047a92e9e7040005b2"sv}, // auto-generated
        Param{"9c6b1c858f8fcdca62247d47366252c9"sv, "151994c8338b8fa4aa737b5532732d55"sv}, // auto-generated
        Param{"ef4cf12bef624fb215c70ccf77c7a3f0"sv, "a0153c75701903a5ae2ef71033581677"sv}, // auto-generated
        Param{"6042e245d847cee2891f880ccfc4c072"sv, "b3df1030496e3e059b0cf160c49ef76c"sv}, // auto-generated
        Param{"61b3a09d1929c26552ff0834e0070615"sv, "69ab1a38fc35a5288dbe4bf85ba3f2e2"sv}, // auto-generated
        Param{"c78a3dea2cf0a98920495f61871f697b"sv, "02df8bc8fc6a73aec9bbc720ada23c5a"sv}, // auto-generated
        Param{"58462a237c8f707f11131f71d0843e43"sv, "4e2991e8cea58f6f39d3b2f2245f2c46"sv}, // auto-generated
        Param{"ba7176dafd52461ee18a90675a7c6640"sv, "de292810cadd12b9583b3e39889517c3"sv}, // auto-generated
        Param{"a018c3d0343e6974a18ec87ad474a3ed"sv, "7d0a72daa3f975f45b1ee1eb23395755"sv}, // auto-generated
        Param{"ac439c1dc1a2e3d1f4b67f96ae78b497"sv, "c9073fe5c347b7d43125325a871c8ebc"sv}, // auto-generated
        Param{"331c7faf2057945f4c61ab87f2468244"sv, "61b8836074022be522c13d6a0eeb5a93"sv}, // auto-generated
        Param{"82e9d5087b59a5335141b30bd09d6b6f"sv, "b106faca801b14a48aa4008842271b73"sv}, // auto-generated
        Param{"6eff48ce4de2d68b455c1fc8d4435460"sv, "d0eb444fe67cbdd08c803a5375793c6c"sv}, // auto-generated
        Param{"73748da0517d4c6d4cde10ea8432e263"sv, "0422f857903472be24946a2f5317fae8"sv}, // auto-generated
        Param{"f08320c12b583ce727e00d35e58881b9"sv, "5cf068c846ecd7d779363c004f519d3a"sv}, // auto-generated
        Param{"e0a826b3a13922ec8ffc9041a799f3eb"sv, "d512fbe7a504f738a6e075ab012a9473"sv}, // auto-generated
        Param{"38d0b53b5b2b11ac51bf6c959ede72a4"sv, "55f3f1e534c7aad38c0b87679383e652"sv}, // auto-generated
        Param{"4a669e5f59fa1b9707b947c7bb55e964"sv, "6bcd34e5fcebd8ba9baeb33cb6ba5e02"sv}, // auto-generated
        Param{"67c6e4268b147d6668863e40d511bf34"sv, "4bb227bb1c478713d51c31abd29052b3"sv}, // auto-generated
        Param{"eec3ad20dbae3d221159aa1a29412436"sv, "761e92b49ec36c8895c809a47bdc9c10"sv}, // auto-generated
        Param{"d80e34ae64bb1dfae4c965640c54a40d"sv, "510629f0f2fe10d766b3647068ed87b4"sv}, // auto-generated
        Param{"378d7ed7f8614b43ec578a007e776e63"sv, "47c69e2fc599a784ae9cfc14159a6447"sv}, // auto-generated
        Param{"4547e71b9cea4340e9f3ac31a2b84c90"sv, "b0188edde8bf3810b199a760e60642ad"sv}, // auto-generated
        Param{"0d38ae38bd557e2382466b62d3281852"sv, "e6aeeb09974d5360a32b5dd00240e83a"sv}, // auto-generated
        Param{"77ddddaedab5d80fede6f5241806b106"sv, "0e18f77f0c6988b87b97b04589f0f2b9"sv}, // auto-generated
        Param{"8af8433949133508976503bab20ec646"sv, "b96f3ad7e7a3abb3d3c147ff32b1604e"sv}, // auto-generated
        Param{"cf04c0f67b6d15c52ee466e6ddd13bed"sv, "0fdfae8c0c0beed9c1fb3537d985eeec"sv}, // auto-generated
        Param{"4f8b2c91c39f5a6d0ef4d3a79614ca33"sv, "5e9741f7b70f95dd77203455917722a8"sv}, // auto-generated
        Param{"7aa818af383efbfbbce7a41289462eeb"sv, "c68e89e5dd7cc29b30b6a2bde729ac06"sv}, // auto-generated
        Param{"e5d44411ac2bc758d7a30840a1d69187"sv, "320ec79155f77490a9456ce875284aff"sv}, // auto-generated
        Param{"5db8d001c21c734aa3c6bcec074e168a"sv, "bd82790d227105b512482edb8be3594d"sv}, // auto-generated
        Param{"dbba87a8453aac88c3367b8898759ae9"sv, "2b183dff0a894dacc7f7ab9e77d867c3"sv}, // auto-generated
        Param{"a45d86281e99674bcef75d186b5efc52"sv, "9a4e0e05880ff234dc7147624ce0ed69"sv}, // auto-generated
        Param{"4523ff71e0214e4251fb41023d3ff63f"sv, "f8fc63c17de9056630ec56450a2f2662"sv}, // auto-generated
        Param{"f41ceff48ec934fc99d42d4d79608b18"sv, "d2ff77abc7500f039e85c3d90f957df2"sv}, // auto-generated
        Param{"f6ee5d8a97c7f8d3662d2a8eb9c1522e"sv, "19ffb537e2bd463208c48c59fb2659e3"sv}, // auto-generated
        Param{"47f9f49abad02d679d1bfcb55e2fd7f2"sv, "58d5fe6b5bec32031893fce964b7a7e4"sv}, // auto-generated
        Param{"66128ca76a71571abb0d8e00d1cb2e05"sv, "6e9a31293db3a8b9cffe1f8c1e55639e"sv}, // auto-generated
        Param{"7dc05b116c27f07001e4ad182238085c"sv, "1d1578d4fe356c5724d7add2df78809b"sv}, // auto-generated
        Param{"81f38cf255c0e0cc7707c480cabfbe14"sv, "a5b24363666dfde1f82a9390ca4f3d72"sv}, // auto-generated
        Param{"018ce1c8fb7733ce60dc318abcc47fd0"sv, "ea620a2c4e2defb30ad8733944695e56"sv}, // auto-generated
        Param{"e48154a7d4680a94bbada15272b87a90"sv, "28bba363ca02a91b9f0e484737712f27"sv}, // auto-generated
        Param{"9ae111f17693060cdd959d1fb31d3ede"sv, "e847e491bdf18cb7d3c5fe5443b6a486"sv}, // auto-generated
        Param{"2746ed5bcd4504916e09ab1c06f8cd69"sv, "fa92a6c305ce20d9cf246f959c3e74ed"sv}, // auto-generated
        Param{"a2df56b13a4ffb3f09e67ac0c6a029c1"sv, "76a11bac688ea16d0364c3758c266f3c"sv}, // auto-generated
        Param{"5aa6a48ceaf963c5b99199424f4a77e2"sv, "6cf25d34db31ce9ac507eb15b2797081"sv}, // auto-generated
        Param{"26962fd72b01f46af4b9a64e5ba31660"sv, "edd2e9d9c3ba944ea1e711d8c80e88f3"sv}, // auto-generated
        Param{"c4b1d79eda09d9a2cce61d4bcde1e27e"sv, "f5512d5da6c817343df37bff267d0bc8"sv}, // auto-generated
        Param{"f672bacf09ffa6721048347a6e234c2e"sv, "0580bba2ff6faae488b9712f44acdecd"sv}, // auto-generated
        Param{"563fdc9282010c316e32d0dc7417ea5c"sv, "2986074859d5460a0ce8d623b618a4df"sv}, // auto-generated
        Param{"510df444ca5d3d4bcd50c8c5ddd59832"sv, "04e784dc5ae023509e767536f4e59ed8"sv}, // auto-generated
        Param{"5b74441d1db17c05683d55d37ab51876"sv, "fd07acaa55e0bf4a4eebc8fda4fed7d3"sv}, // auto-generated
        Param{"939aa49bf3043124593d0a4bf55e9b17"sv, "185d2c439e47a36886fe859c5181575d"sv}, // auto-generated
        Param{"3f37878c61d8cf914f40f87b8361a78d"sv, "c1b588c1fa7f705d20020b43ada0644e"sv}, // auto-generated
        Param{"b33001ff93ca6b9ccaf98a1e3a00c5f9"sv, "a0b12785cbf890f061761b4ef32e6212"sv}, // auto-generated
        Param{"71490be0528a802d979888ca2a642b49"sv, "3e7049ba9446c9865119b991aef0f7ad"sv}, // auto-generated
        Param{"36c69862fbc6fdac7fd0fd44cf519390"sv, "f1179f05927e4cfeee0671d1df84f3fb"sv}, // auto-generated
        Param{"e882cc7406aa900fda6802664072c638"sv, "fe91a0f1e2906301f6efaed9889c1dba"sv}, // auto-generated
        Param{"b017069855711679675e3b68c4183cf9"sv, "b5c093d89cef71c8f9b25088c4bbc3fc"sv}, // auto-generated
        Param{"41856ec96aea8fee167f60105fd5829c"sv, "5e0da629d409e970f2af8011711ba68b"sv}, // auto-generated
        Param{"e395be1755dd1df80c3f083a95b1617d"sv, "a8b2c1fc6cc40bf55f9fc0b804bc62ab"sv}, // auto-generated
        Param{"cffb4195df183edd27d0f0760a66441f"sv, "847ce49ebfce39b197a703613d4b5452"sv}, // auto-generated
        Param{"24caf0bb1170502b0733d35bfd158155"sv, "70a83aea34fb34e27606c2354c0db892"sv}, // auto-generated
        Param{"a579187e6792abb5c83f23366b0072b7"sv, "e77b863887f6d265a62fb8047fda0352"sv}, // auto-generated
        Param{"a3b3db4dc71fc98d7f10879e5aad8637"sv, "da40b7b59444bb6e52b84b1d60e33ce9"sv}, // auto-generated
        Param{"86146fda32dc31aae6662bb530e41cbd"sv, "58eecf983dc712d1c735048b64384213"sv}, // auto-generated
        Param{"c5ffd43c5aaf95a3fb5dc67c4bb95a51"sv, "6db61d9b22ac98aeef11f777b5719d60"sv}, // auto-generated
        Param{"35ac4f12dd62e3bed1f3fdd2dc2a5ea4"sv, "e176b2c9069ad6df54cc3b2ecf5274df"sv}, // auto-generated
        Param{"d86c74ae1264a3c54eab5015cc9c8567"sv, "a2257b7b7b6b67a0f4dff13a3592d54d"sv}, // auto-generated
        Param{"4d06dc959a914c73223c60174b8be5d3"sv, "11e8756c2294ffa1279f154b1ab63e98"sv}, // auto-generated
        Param{"2b261d12a23187d8c13e6577c5ea9ae8"sv, "79bc786c5be2aff0b3655b6de3563270"sv}, // auto-generated
        Param{"93df1a5d2ccb433499152fce7149d309"sv, "148721dfb87c6db47b7ec1663c8af0bf"sv}, // auto-generated
        Param{"27192cbc364d680525ec7c6d995ba8e3"sv, "80ed1574a452984a5c30d36160b76e52"sv}, // auto-generated
        Param{"1a92b5beb540dc4c0279fcb43ba9cf2e"sv, "a58161593f7dea29a938aa111f99d4fa"sv}, // auto-generated
        Param{"d4ba685a9ce04009bbef306f3e9f6b2f"sv, "ad4b4ebece184ef4cc0650748ae33a41"sv}, // auto-generated
        Param{"4db4b8055bf1e40fb75670a9f311b87c"sv, "e9f26544d4706bf3abe952a67eceb4f0"sv}, // auto-generated
        Param{"19d58e7aa276c5e337764fd2fb17ab88"sv, "bb3ec66e9cf62fffe543c395dc80ae5e"sv}, // auto-generated
        Param{"c8550b1ae41402282061e590d710321f"sv, "d07a9f472fb82a03ddb7ee3b65dc26ba"sv}, // auto-generated
        Param{"f7569c85becd707081b8a84dd9c8e714"sv, "bb769b790dec66fb9d8a7fb952912da7"sv} // auto-generated
        ));
