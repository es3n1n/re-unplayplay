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
        Param{"52f5a2b7ab3130efc7a9fc76e873d4b5"sv, "241608b73ff02eb0f38c9fe0f5ad1428"sv}, // auto-generated
        Param{"22101e293b42eafc739c72143319df76"sv, "8ea0088033e4ca4743e5e074bb2a870f"sv}, // auto-generated
        Param{"c75e1b9c224407dfcec551ce982f2d9e"sv, "e2a56ee79dce10acc9d7cb3fb6c3c20f"sv}, // auto-generated
        Param{"0aa6501bdd8f8d8437ea645eaa5a7b29"sv, "00bda41be26c644f81a2a46245a2fffe"sv}, // auto-generated
        Param{"3cc72c82cd42aeeddace85ee0dade17c"sv, "36fdefaf14dc13c1155fe356490b6d57"sv}, // auto-generated
        Param{"6add071bc9a2c906631cccdee7c8d7ef"sv, "2141d32af812b8bf1c6a8cc1bea6fbaa"sv}, // auto-generated
        Param{"72c490c6570af3c440ab54d7592736cf"sv, "2226ae9ad5a45a17e126a9fa6a280f94"sv}, // auto-generated
        Param{"4c0aa9773d15f1df62b335c137c03d79"sv, "0ccf7a73982b47fcc44191caaf960be6"sv}, // auto-generated
        Param{"c75d76d6eee9f3973e290b5eb07046c1"sv, "c04a31b16677853a6d07e8dd3c29d6c4"sv}, // auto-generated
        Param{"371646fbf54091e354911b1d09f40667"sv, "00978e5989379a200677d536cd73ec2a"sv}, // auto-generated
        Param{"b6d223101925fb736f13405b6ef6828b"sv, "4eea5fd6da81b2df72c3d855d1e0aead"sv}, // auto-generated
        Param{"a9dd6a412aacaae7ecaee5b70c67c968"sv, "d49842f579f80707a13fcc5402737d82"sv}, // auto-generated
        Param{"4861a0358ec7015118ec750f04bb7fb4"sv, "fc99613aa2fea4b07f2fb4ed1dd1b706"sv}, // auto-generated
        Param{"af4d23887f50e124abcc92efeef82571"sv, "a0e14d7f445f6942514e9ff09ec89f8d"sv}, // auto-generated
        Param{"dbc56f5ab41998936c8ec2b8778acdb3"sv, "019e267c575c8e4f9f4912def4c8750d"sv}, // auto-generated
        Param{"b506a5f8d73dceebb36d4352013642fa"sv, "8087ed12afac7595940d4b735b38ed46"sv}, // auto-generated
        Param{"89a7682c5b276ec15acaa58d0c39a314"sv, "ced9b9ff3370ad56bfb24693c1b9d1e2"sv}, // auto-generated
        Param{"04d10cbb3502978389be563beeaecfce"sv, "70e5b743649e81f101f79d22f548d0ee"sv}, // auto-generated
        Param{"61bafab84034e9ba9b41dd1b55aa617d"sv, "034b48fc5c0cb84b9b7f56845160abb2"sv}, // auto-generated
        Param{"aeeefb89de6f60b0900dd437053b273f"sv, "c3b055d728eca6783c351cfae63769e2"sv}, // auto-generated
        Param{"15ac5ea9d40090069e5265756f8ca61c"sv, "7f36d2db538f73ff186526db82075cc5"sv}, // auto-generated
        Param{"882bbe3f283dbdb63b32142b220df739"sv, "a7c8ffde983d459516ca3ee7b70e2ae2"sv}, // auto-generated
        Param{"16f0446edd44147e42788a0b221fc56c"sv, "9a6f04887a97362a5b1cdc90f9297c90"sv}, // auto-generated
        Param{"2baf36910a7d4273991c9f5c91ea8057"sv, "c5823688426736d4512fe67faf1ef6eb"sv}, // auto-generated
        Param{"8863a958e6aa9b293a2cdc16ffcf9242"sv, "b1b5b5410b15512b991e363cfa16a5b0"sv}, // auto-generated
        Param{"fe652c718aa04e8d65f04939d272ca41"sv, "4e2d7265bf45d458b07e2bf76e8ca26d"sv}, // auto-generated
        Param{"7985896e85713d426948caa504d3bd55"sv, "558e1ced10d333a4ab95780eb1bc3a59"sv}, // auto-generated
        Param{"4bbe085f2ec869ffbc3f363b228fb6ef"sv, "1663cdc674540b0ea6e266f1eebc776e"sv}, // auto-generated
        Param{"c0612b358e18087aeda49ec78571039e"sv, "31f6dbd3a5048b4a9046faf3a379addc"sv}, // auto-generated
        Param{"0723ef68966cf25963c31eae654e7b09"sv, "c513b8335a926844f14dd4396d0f3027"sv}, // auto-generated
        Param{"63011d6b0d709e62bd61797abbe85466"sv, "7617bcbc81184fdf196239fae88706d1"sv}, // auto-generated
        Param{"285422221f99bff465e499e7efc93da3"sv, "9125c689139eb27f8cc94227bed5deea"sv}, // auto-generated
        Param{"de2d3715843330c2a7a79b0c57c82347"sv, "78812bf59606605e0a09717a47765a49"sv}, // auto-generated
        Param{"866f2b0ab880af89c5069239ddb3a472"sv, "755c4e98944faab1d5e3d4c642fc2719"sv}, // auto-generated
        Param{"f19c1192442678c3f88bc3d6400b94d8"sv, "e7ba92b35db35c249842d837958bef44"sv}, // auto-generated
        Param{"c4c05f28b0ca26f79b4648f797adf7bd"sv, "06068ad71a2d039499ef38a385a7b429"sv}, // auto-generated
        Param{"a37996794b0f4ef3b4bc8009fa50cae5"sv, "9b833d74fd0e2bfdea3099eb066e3900"sv}, // auto-generated
        Param{"0805ac917ffa1ce55f3acd43d37ce117"sv, "df1c3eb00bbfabd1a2875b0e76aa0218"sv}, // auto-generated
        Param{"82309a8b8088748c482668aee666742b"sv, "7ad733be347d60ae4b51087d1d6d5fee"sv}, // auto-generated
        Param{"0d2e5d6204c9570dc6d6f46f7a7da7e9"sv, "3ac1d184790cbcf9a73e32b218ac2bbd"sv}, // auto-generated
        Param{"9d6aa07b7b7acca356961115831fa0e6"sv, "33cb334f26e577443579536e54a120fb"sv}, // auto-generated
        Param{"e4f964fafc89efcda8bf0c4262f013c6"sv, "22f410bae7ef7ebebe2edfeb2474e14d"sv}, // auto-generated
        Param{"46b3e2976a28d5a7c9d442be5e811252"sv, "6b39cf0d545db5a99cceaebb44ec7130"sv}, // auto-generated
        Param{"cf2a1df31591c425ab3c46eaa666abec"sv, "66ef142e42363a74ceb3c33ffaedf247"sv}, // auto-generated
        Param{"e632a77faa973ef7cc3c63cfbdbf04e0"sv, "d45f7b9b954945d6797f28ada8621e74"sv}, // auto-generated
        Param{"6ee799ad162afea29d04b0d72041a67c"sv, "e0f369dbf9edaed85b82c26357c5991a"sv}, // auto-generated
        Param{"2dcd727df31f813a224bb7a756952813"sv, "3940bbf87ed70482aad423179376183d"sv}, // auto-generated
        Param{"39b074fcf8356d0ca7fa2cac7c710c68"sv, "b8d8620222a425e6da7f6458a83d3ec8"sv}, // auto-generated
        Param{"f101dfc2d0d2aa555eec4fdfc475c2ff"sv, "127eb4d45608e87f4e18112dd52cf1a9"sv}, // auto-generated
        Param{"7ef66a043afa30272ff5e7cc228b5320"sv, "44f31b56c8d1cefbcd63686ca65f9e0c"sv}, // auto-generated
        Param{"13ae22cb940e7f54d14f916dc33d8c20"sv, "dac57b39a5fcfa071064ad8fe0080591"sv}, // auto-generated
        Param{"c87720dd99dcaf5592c74a6945e381c9"sv, "0db1d33ff9cb312d265d68a76ffd2919"sv}, // auto-generated
        Param{"540fb516d47c367f98af68438c8dc22c"sv, "f3a2b8aaecaf79c053d08038e082d934"sv}, // auto-generated
        Param{"7bb561e6e4b4790c9ca269ec384c6440"sv, "8e2f71b15318954555966ffceee42dd2"sv}, // auto-generated
        Param{"dbde64b675bb97cf9f02d2204e6a37cd"sv, "82072c5e0d29f50a736b43fe6ce7c498"sv}, // auto-generated
        Param{"4f444405cb708bf8f17b87f5539ad010"sv, "c69de51cff50c36d0996bf4143a93a42"sv}, // auto-generated
        Param{"c0ed8673864bae9cffc4763f0c68de5e"sv, "c3d693c3b73a5fca6edeaf30fe0f3dd9"sv}, // auto-generated
        Param{"da42c0b0335d06e8efd05e9552438a95"sv, "62e0debbc159f02c26198ad668b19ef8"sv}, // auto-generated
        Param{"388cef62f9d5fcbb0ac8a659d33d0922"sv, "70943009206555b4042b1505388df95b"sv}, // auto-generated
        Param{"fe33bc618d685859458b71cd95fa6acc"sv, "564df105fb836eb40b08c31710c00d65"sv}, // auto-generated
        Param{"02135f712b2c1d2a97382646ecf5bd01"sv, "2d4696c08be2ff7b1b68fb375bf940c2"sv}, // auto-generated
        Param{"2a97588aaf0fec4991ce33096689057e"sv, "1aba8814368ad547e34bcbedee756ea4"sv}, // auto-generated
        Param{"0bb01933dee356766c2c2df1d5158299"sv, "4e8d32043ccc45cee74a79b9e213c9c7"sv}, // auto-generated
        Param{"d48476002ba51fa75b0218595c2d19a3"sv, "26a192919535325be036234555221cbf"sv}, // auto-generated
        Param{"adecc9c934218bbe597af1d6bd5ae446"sv, "fc8529c6f63f064a941fb00ddf0e1434"sv}, // auto-generated
        Param{"b170eff3494c94761054b10595245227"sv, "c8d8362c5dfff8d80e087f9ba2aa99ae"sv}, // auto-generated
        Param{"1b24bf22776019401fac2559444bfe7e"sv, "1708275f07fcabffffe02dd82b2100b6"sv}, // auto-generated
        Param{"26846bcbb1abebd2bc3087daab4bab10"sv, "79f2aa6b158af70afee902877aa06857"sv}, // auto-generated
        Param{"e2d5df6054de5b5f43c4f44b40d3add7"sv, "3ff620bac53cc4cbe0e26d9bc0e5fb2e"sv}, // auto-generated
        Param{"16f4b8ede0e9fed6d6568496ca2ac4b9"sv, "398ee313d6601b6c6d2f2a93b2e0b20a"sv}, // auto-generated
        Param{"bd8ac7f86579723bf936b1ada375d0c3"sv, "508569903dcd25f066021d5b5bc62031"sv}, // auto-generated
        Param{"2e4fb99735b67549c8bade073d03f8c5"sv, "4deaec6b9a4fa30489cd8a6fc095f0a4"sv}, // auto-generated
        Param{"41fb0e697aabb904b4cec4e0aa5ae7cb"sv, "0034b8f6feefe7e7f4ae020af9d0804f"sv}, // auto-generated
        Param{"c7e4af48b243d24c27b112c56a2e80fc"sv, "a391665b9a654e052f80dcc034c9fe11"sv}, // auto-generated
        Param{"b6c920a67ca9af290f16db38cc61562a"sv, "de2041c12e59212fdfb9871419e0d274"sv}, // auto-generated
        Param{"53bf188a408f1fb2e872639440f7395a"sv, "9101307ffd460850716c171a4db71513"sv}, // auto-generated
        Param{"db3125da94d0d2a48fdf6c0100f81318"sv, "4993071bf8ccedba4922db93f327dad0"sv}, // auto-generated
        Param{"643b877985556f88e25083d6697f8686"sv, "84e812936313a299d5353de5d9b49f29"sv}, // auto-generated
        Param{"0df167dc31ce8d631e3d96c09ef91226"sv, "9a96c66f0f27f5f31cd4a42c73c56130"sv}, // auto-generated
        Param{"445f07dc0fdd3646138bebcc14b8dd09"sv, "72c1d12716a0f656ff8c2794accfdbbd"sv}, // auto-generated
        Param{"095b47e95f4af04ffcd6ded097c035bd"sv, "ac3e8406ca90758d594386d3d6e44e30"sv}, // auto-generated
        Param{"b286785e61f6d27e04131b9e581c0104"sv, "226331af4005e3922a99477b97155bac"sv}, // auto-generated
        Param{"bb7f0c8b9b47deabc434b76f7d15e2f3"sv, "f9ad3f983b88886f582ec40fa8a94e8b"sv}, // auto-generated
        Param{"895e28891ba9d703bd523448931b9a26"sv, "4657f559d44b28887986b2595d89648b"sv}, // auto-generated
        Param{"69f7a5d375bc1af84e1e8526548d11a3"sv, "821bb15a0d40b28cc8a45a9be0d4dd37"sv}, // auto-generated
        Param{"6ef359957f0520397cc746ed4a1d407a"sv, "49ae640ec18b36450f95612c7ad2e01c"sv}, // auto-generated
        Param{"2e9dddb56e2bd271003d9f0107e3a5fa"sv, "18d783fdd05eeca5d72e6ceee37beeba"sv}, // auto-generated
        Param{"9fcb7a9aba4fa3dedc7c9e2f17257cd7"sv, "3a35d9326f460a0b7d593ee9d9073363"sv}, // auto-generated
        Param{"1862b197acb00fcc0b61e7f0492c0669"sv, "8fa1facc45ff7ff5c8d79b68b3fd75e3"sv}, // auto-generated
        Param{"014503bfc43010881715e1c5dfe488ef"sv, "8d32f1eaaa37898f1b1ad6c1b6f709b6"sv}, // auto-generated
        Param{"c6282ba0e5ea86805f323abc715f1c25"sv, "3a9d0d0a809395092bb03e096703121a"sv}, // auto-generated
        Param{"5fa8a6ab5974b411b8b6dd1e8403edf2"sv, "5bdbdbff83a9e6223953a16fc04200a0"sv}, // auto-generated
        Param{"d09ea08782c9dc286d441276e034d228"sv, "37a4b0898f6bfac44c93e243f8a4925e"sv}, // auto-generated
        Param{"6602b4959e2a2737f07888936ef195ad"sv, "d26e1c915a77681cd4967adc32a3e558"sv}, // auto-generated
        Param{"0f80e6d97917afa8feb2d1f9a7d8b19f"sv, "d189f46681f5ce4c99cd1d08ac38fba0"sv}, // auto-generated
        Param{"91cbf84bf96272f1a424103ee5e76939"sv, "8fee2327cca5922d147f11383d64ae6d"sv}, // auto-generated
        Param{"ef31390f9cb77cc3ac6c231246fc103c"sv, "2e7c6af14f4b938c3d0beb3b921a1c1d"sv}, // auto-generated
        Param{"6e2f797761b3ad64043bc860052056f7"sv, "f397c0cb0fba8572d130f63c231c47bc"sv}, // auto-generated
        Param{"dd7a5be1b400eb5b5a867f483479b32e"sv, "311cc0573d8cc3963f36aaee66faea0a"sv}, // auto-generated
        Param{"b7a6bad4277905aed4c7beb3ebdf37f2"sv, "1f2887d38ddad83c7a97303f50546a06"sv}, // auto-generated
        Param{"439c46fe7fe314f2cba526817982e388"sv, "b45c6f6e9c77e42d208d1f0285ce2164"sv}, // auto-generated
        Param{"e3f67a0f5f69f63e8a6f90cab0cb1c34"sv, "43c796782a43a4a39d14a028cd62b1b8"sv}, // auto-generated
        Param{"63bf5331ad1fb5cf25084359eb53da97"sv, "3ae64b7d890a29b413e6b923f912f771"sv}, // auto-generated
        Param{"ab600a258baebe2687b4448d5279f9a3"sv, "09ad0c38415b407d818be18688793480"sv}, // auto-generated
        Param{"38c294934d9b6b73a35866a0665068b6"sv, "77592b0c750ee07dcbede29e81064f56"sv}, // auto-generated
        Param{"95d5a5a414ff98352532d4361e35bcba"sv, "845977f014c2c1b7bbd0c87aa6c81fee"sv}, // auto-generated
        Param{"b9b0819e21b2cb974ca5e8f0a80a2cae"sv, "6583d258b12b0d87b583a634bf4313cd"sv}, // auto-generated
        Param{"cb96f611b4af131f34af38e2d81ee781"sv, "64a04e9d52885d75c292c60084036048"sv}, // auto-generated
        Param{"cb958316b1f05136f8e8734d006903b2"sv, "1d573b97e6c7269e0a1cf9ccb30821d5"sv}, // auto-generated
        Param{"3fe30123b0ae40b1a4b73c8be9dd0fde"sv, "ce4ae25a5b1991ee3bb86f6ca5012734"sv}, // auto-generated
        Param{"09f358824e25efe3737c5b904b6eda0f"sv, "8f6f7919b04da2f607011aced84b1c44"sv}, // auto-generated
        Param{"f6d202896dec24ae7978a2faf15be7c5"sv, "ea8980c308069829e4d7c98850b71a81"sv}, // auto-generated
        Param{"36cdb1237503878853630361ef600239"sv, "cd0fa7aa7e42335f5467ed301bf8600d"sv}, // auto-generated
        Param{"a83bf24a9bf41a44aed0eb90076e0b38"sv, "ebeafde9784f413f214ab2789936a637"sv}, // auto-generated
        Param{"197c2444012f5150674013149f61ac23"sv, "b7a8ddb625aa61783fab49f8a3e02427"sv}, // auto-generated
        Param{"a9395aa0859d1d561dfd577fe7f212c8"sv, "fce1f1e6936542b0b3a74b9fa83d734c"sv}, // auto-generated
        Param{"b7714e610aaa38f81e68b29dbb4f8cd8"sv, "8feba3741f695cf8c0d5f472b60995ff"sv}, // auto-generated
        Param{"bf6e4f43ee1748044a75b23c9c6e7f59"sv, "ec9e279152c744b409c229b717fef9aa"sv}, // auto-generated
        Param{"3b59cef8b0dcda391835f3a1430d209b"sv, "0bfbc95112cf0a9143cd9c7099b530af"sv}, // auto-generated
        Param{"557de3b7206ef8fe3ec796f25f3f6afb"sv, "1ba88bba45cd39042be11fb30f422f8e"sv}, // auto-generated
        Param{"6c7171dd742c4f2d6df019464e749502"sv, "f51ef4558550161803b5101ae11bd851"sv}, // auto-generated
        Param{"f30117d43497e0e3f45d36c31a64797c"sv, "a3238b5c424cc08f1d9a61179ae901cd"sv}, // auto-generated
        Param{"636483634225841ff3f5cebe5d6da70d"sv, "00c8e0fc6cf30af540da95145f4c3c95"sv}, // auto-generated
        Param{"68bd951131465fc60d7919050bac8e7d"sv, "cde532e9f6b8c8f8534e2c989777b5fb"sv}, // auto-generated
        Param{"d83b5503b4dc0b3547f6a203037561ae"sv, "2ea11bc642487bc8e6328a22d036b291"sv}, // auto-generated
        Param{"16ec584b3ec6806a6daf7722500dc3f6"sv, "209ecde5387bd7ab11d7e249ec41bdcc"sv}, // auto-generated
        Param{"ee29bafd50203a7b486798ace7acbd63"sv, "b3fa3ded3bc941f712bcc3abd52f4daf"sv}, // auto-generated
        Param{"6ad382455149522ffde4402bcb6f37a0"sv, "6089f5d3e6e9cf74491233c0efe4ce52"sv}, // auto-generated
        Param{"611472bf5b07bf951d163d3b0ffa6e63"sv, "726f5d45ce47459575584e6633d00828"sv}, // auto-generated
        Param{"664458a730e79f6074afc9d986b4e74f"sv, "d0b364eddf5eb29e9ea4b809cef812af"sv}, // auto-generated
        Param{"c8b68c0e78ae1b5ad098f177cfbd4bcf"sv, "2ccf126d73cf59c9b978795fed70a283"sv}, // auto-generated
        Param{"32407a40ac7462ec581c709cb948e5d0"sv, "3f2d4e8c669030f03cfa99228dd2c52d"sv}, // auto-generated
        Param{"4c780213fede91e8917540b68cdf1798"sv, "c21df9ad10ff7b6061621e542b0be3c1"sv}, // auto-generated
        Param{"e4fa11876c593a40d508c2488b56b589"sv, "cd7456fd870091dbc8a83e241111ba6d"sv}, // auto-generated
        Param{"44b19ee137e4a9a3a11608865e554fd4"sv, "b2161ceb3b26bf41ac0b4dcb6188fc90"sv}, // auto-generated
        Param{"fc2ed7d090f7a9f9454eb45f846738e2"sv, "e938e9cdfd84073b06e095317a5753d6"sv}, // auto-generated
        Param{"fc1339e680e6c681a09cab78d2aff094"sv, "8209e0282ad97752587a6822681cd2f1"sv}, // auto-generated
        Param{"c125bdab788fd1a47359a57029507c3b"sv, "d649fb4b1f1766b69f882fcd2020963e"sv}, // auto-generated
        Param{"2084cc62bccca4fa9893b210f0100c59"sv, "eff2c4b83b4207dfc6440db6b5e2bc63"sv}, // auto-generated
        Param{"efe67d44fd43a07120d0b18434e86c17"sv, "54bdcbbd9fe3650cabc111ad0b7ac6d4"sv}, // auto-generated
        Param{"e04ff979e82fb5f4dd94c7ea933b6769"sv, "bee61651a1d5676d7de76b9da5bdfe96"sv}, // auto-generated
        Param{"af0ec54799bc1b7a47df2fb913c09113"sv, "e7ab2235a35aa5b7428f8923a17fa81b"sv}, // auto-generated
        Param{"d10fb8aaeba9cec52eb75ece5c8f20b7"sv, "51b1b3900ca82079d2b6010e00ca2b40"sv}, // auto-generated
        Param{"4839bc10b67ac4b3f5b6c1fb5ddfffc8"sv, "26ee0c697ab51077416d9e684afeb71a"sv}, // auto-generated
        Param{"3e35e42a0ad87f2fd39d599d8cdd2021"sv, "dcfa6cc312dfc94d99415181c7c8abac"sv}, // auto-generated
        Param{"a1ef9ebf7955589c152b3fd38d895e47"sv, "4040d667f0ddd27d63a2eeca71d8218d"sv}, // auto-generated
        Param{"447c7c783db8ab9eb290c6737c68f825"sv, "00a4d7924d91b20e16fd6a262d1a65b5"sv}, // auto-generated
        Param{"34bb6c895cd1e4ab2d941b31e1563ac0"sv, "6020c26a5b71af196e505f6dced352d5"sv}, // auto-generated
        Param{"7346ac827546651eb98cd79dda7beb0e"sv, "1be7ba7c455561f061428f4300b086f3"sv}, // auto-generated
        Param{"91935c60c44820dcac8b56df5f2005db"sv, "4f4080fe9cc6660fcf3668cc2b07ebba"sv} // auto-generated
        ));
