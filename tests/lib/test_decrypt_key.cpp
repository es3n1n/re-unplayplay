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
        Param{"ff121852b3d92698eed4c53d89fa4ca8"sv, "dd8ea37996412be0885cd29a703c483d"sv}, // auto-generated
        Param{"bb9c57f716a196b5329dbf0f851089b4"sv, "3a6497e635b273bd5e677a663eca593d"sv}, // auto-generated
        Param{"a5b3baf38f1b7b16e735dfa35fbb9b66"sv, "ce903463f1fcf294efb643f02dc0ba51"sv}, // auto-generated
        Param{"f7d7944489470912fc1a3a9e44047d10"sv, "ab4a947f52e7d55ec6c66866f61b2687"sv}, // auto-generated
        Param{"728b7527c56dc67f1c5240629dfb5723"sv, "edb745a62bd5a5ca3f9b487fd5976c8a"sv}, // auto-generated
        Param{"5a86be8f51047b12c28e6bf44845c88f"sv, "061f06d31942bbdb5d0842eda01fd5ce"sv}, // auto-generated
        Param{"2becd4a400ab2ce799537b2d5073c623"sv, "d18600a55860bfc709b08fca41e5e8d7"sv}, // auto-generated
        Param{"ba69da78f6614d8cacf52bae1f66d160"sv, "07cd5fcf9cd381ab6947abf6259d79fb"sv}, // auto-generated
        Param{"b525fbb682413d772756b87fa932aadb"sv, "b75ff611793ca3d42b7e5ed35a5138a3"sv}, // auto-generated
        Param{"f4fdeab86721e6c2ae0447aa611264a2"sv, "52713a1d7bf2df491d0b865a2993fd4c"sv}, // auto-generated
        Param{"40518eaa85932b9f3f63388fb76a48a2"sv, "e34270c8eaa503200c192fd41336eb84"sv}, // auto-generated
        Param{"ac3621137a8bbe06421f181f60f48e97"sv, "dc61a3f028ef5439555651d6165749c1"sv}, // auto-generated
        Param{"caafa3a23fdfcc7ea7376a6ffd11ea4b"sv, "d4bb62cd4b40e03b0103ecef29f80ce3"sv}, // auto-generated
        Param{"912c12b9c463842e180a641290c2b4f8"sv, "44d80b39ce177374332cbc0349af4913"sv}, // auto-generated
        Param{"2809b6519ad74754ee74623eef9aa5c0"sv, "394e7db52349c820d680d768a3b68e22"sv}, // auto-generated
        Param{"544a8b85d6111d008382a22813625bb8"sv, "a79ad0a79bb1afccde300cd966e76998"sv}, // auto-generated
        Param{"fbc99cc1cb186ea13207951119178f13"sv, "8399354ba83e9ce7df6136f7ac95ade7"sv}, // auto-generated
        Param{"127f190a4460b7bdc2e1ec0b2dfcb37f"sv, "98e2b6e3d6daa357e407b2a99ccd8e69"sv}, // auto-generated
        Param{"495103b3fc2d9df3dcd0df634d01da98"sv, "005775ed1d3abb1dbc757030ea34b2a0"sv}, // auto-generated
        Param{"f1c3cbe61ee454f8e9a4c3eaf7135332"sv, "bd688091bb25d19bd03b6841a81d461b"sv}, // auto-generated
        Param{"97a5e636dfd26b087d8e2850a8163b30"sv, "d63d5d09a8aac07f44b32d870a350659"sv}, // auto-generated
        Param{"3a5757be5e881dd7c1c19fef1fed751e"sv, "6317f62670c583bc6ee292d5a2a4b9eb"sv}, // auto-generated
        Param{"4be0bb5dcbd97b7f765d691caf3d1719"sv, "da50597b79648075ed25748caa0a981b"sv}, // auto-generated
        Param{"3a01c967707e3150438af708b4be5300"sv, "f48e38e3c7a8ee1fb8c8621075d84be6"sv}, // auto-generated
        Param{"b95c37410407b1b7c9112959aca07e27"sv, "da824f69dbbbdf0ef431e388dbbb067d"sv}, // auto-generated
        Param{"8f01bb027dc903f9c1223bc6270a91f4"sv, "f08092eeba53e95e7ea1ea3582bdd669"sv}, // auto-generated
        Param{"c99c2ee9656b78491f3244cfcd99214b"sv, "c6bd23caf961f7396f98bb4b97b34063"sv}, // auto-generated
        Param{"bf4c83bfd4b0a327342a0365b5e43973"sv, "dcb09bc7c4dbc418395e8341c88db26c"sv}, // auto-generated
        Param{"890ccd6c2ae90e90bc26430c232658e8"sv, "b6db1e6b1efca8be16b4c4e452a0a03a"sv}, // auto-generated
        Param{"98cd484e3207e6fb4a9672773453dbdc"sv, "100a6f4e479f136ff2dba31c6af52285"sv}, // auto-generated
        Param{"7a477befead355999c4c0d33026415ff"sv, "74d59dc678d7389af090d04bc43f715b"sv}, // auto-generated
        Param{"da5649d4c4f9c7c5ec332188b4cbf1c4"sv, "34f3f01f1031df2e19d2b66e7d16b56f"sv}, // auto-generated
        Param{"04d4ce83472e832b06e216f8db3b3ed3"sv, "4205ffd9516e7d2477d531175447f3bf"sv}, // auto-generated
        Param{"87b1662fb70de4043b9b1320f03c5282"sv, "b49eb9f0cf8fc8bd2ba52ad8ea724003"sv}, // auto-generated
        Param{"63336e8b516e1e2b08e2da3edca28fe7"sv, "6a304928c15e5fd8ef7b730fe846bcd2"sv}, // auto-generated
        Param{"7965cee3599402e7ff1219bf57936b39"sv, "fdb2bc6e831de55056731fc615598eb3"sv}, // auto-generated
        Param{"ac77cc085f78da29e285dc2e7855996b"sv, "8d3b87e83b3528f693dfe03624e6e97f"sv}, // auto-generated
        Param{"673642baa3ff0d05f14b5de811168096"sv, "11fbc73fbd73c2f85bbd2db0391dc663"sv}, // auto-generated
        Param{"7cd11341fdb66f419a1e4b0e47c42103"sv, "7a10292a4fb41a1f4bed1742af9e439a"sv}, // auto-generated
        Param{"664982d484edfe010fdb524f25af5a23"sv, "f444b7572a3e6ceaf178178bc2cdc27f"sv}, // auto-generated
        Param{"d5e3ea802f1fddaa708a34bb90b2396b"sv, "59c77d1856490b9b83eedc3bf830d6e8"sv}, // auto-generated
        Param{"572a6f610b512624c651202edf66bb92"sv, "0ba6b29e93c1688868dbfaec9c8d1422"sv}, // auto-generated
        Param{"e9820c1d182f8e1454e3ec669b69d04b"sv, "70ea407ea5ed08567e78670c7172cf2b"sv}, // auto-generated
        Param{"8a8d697d63bcfd58ae0a4dfeb588d7aa"sv, "a6660198942ea9febe1f1e0a219e39ee"sv}, // auto-generated
        Param{"c32cfa046827131b34b67a8237b142b9"sv, "efa8bdebe8bfe5a61a85e0965d586c29"sv}, // auto-generated
        Param{"a7dc81de59db93be36cc5cbf7c4f642a"sv, "b0fb797310e847131934bafb90871a16"sv}, // auto-generated
        Param{"d43c567cb2ace22acedd7cf964c6929e"sv, "89ee811e7a881e63b388fcbafb1023ca"sv}, // auto-generated
        Param{"53bb4aa485232096d9f04e0b6af32a85"sv, "1a182f7d25123db212bf649e35c38348"sv}, // auto-generated
        Param{"953aa2cff40b86d9c9b7abb0c4bbd0cb"sv, "3eb15bdb063aacd321e2eb473119574c"sv}, // auto-generated
        Param{"757ec64042c31515d0ef02c90525187f"sv, "5d87e0b39727762863959f2273deda6d"sv}, // auto-generated
        Param{"9a569714c3c8648d70c178aaa6934fc3"sv, "80fd2773477d7199e1025bf40abfe7ec"sv}, // auto-generated
        Param{"911894d71af239ec46b436e6f3f4d495"sv, "8b39734961ad7de325dc0458bce090b9"sv}, // auto-generated
        Param{"685b2d46fce6c2d10e899c0e98e919ca"sv, "ab4af7d1056297f7794a43dbafc375aa"sv}, // auto-generated
        Param{"16a15f8eb4b150012d8f1d4a4845e5d5"sv, "79f580c974aa03417e6edcd514d3f65d"sv}, // auto-generated
        Param{"6fae741f8655389d82fb45058a1c702c"sv, "0a955f7ec424e8ebdb5a2ef94da06175"sv}, // auto-generated
        Param{"fcd1db82880e8aac82dc5084f41e3c9b"sv, "46acb468bad6d4c0e5b7996a51d3925d"sv}, // auto-generated
        Param{"d411f724e458022e895182be71f8fb55"sv, "8a0e9b4e327ec18007008d2f1b5336aa"sv}, // auto-generated
        Param{"0de1c784d9e30192af3bcb4a771ced5f"sv, "ea64b3151271e9bccc13e6a35b7322c1"sv}, // auto-generated
        Param{"614a917ffafe545c78a9b022760955e4"sv, "b775adf0bd9494b5b39fc0b051e41a03"sv}, // auto-generated
        Param{"9440a6a9e55d7fb63ed3d477e486cbf8"sv, "c9f5ff6ac4ab7d5f922af34056aae7fc"sv}, // auto-generated
        Param{"a266393b2d499c86cc4e6342c6cf7384"sv, "77c877d2d3eefa8ddd2179a7fa696cdd"sv}, // auto-generated
        Param{"c5bc771def831dbd60d153dd4f09477a"sv, "5ed786012f9aaff5a17a9fdfe6b1ce19"sv}, // auto-generated
        Param{"2670c48ba031fc684916e42a4f27cc19"sv, "8ab27b6fd43dc361cc4db53f319d26c4"sv}, // auto-generated
        Param{"176818cc4970ae1596bb2e9570ab8a98"sv, "7f49f68a837578e3e66956aa96aa4e8e"sv}, // auto-generated
        Param{"070be3a1e925e67c4719f10200912358"sv, "9816c48c3113e56d4e9cac3d9fb69ab3"sv}, // auto-generated
        Param{"d0f19bb3ac0c7cab94cb90ad7fcf1779"sv, "87ed31b052f4d7a0a7333b6b404a4316"sv}, // auto-generated
        Param{"cfa186507017bf72816b8e44d98c088b"sv, "59514d81ac1d4e52556584a4cceec42e"sv}, // auto-generated
        Param{"bde76242de7ad1a9a70f5654cb56cf91"sv, "facaf480494b643b8e3647c1a64f86c1"sv}, // auto-generated
        Param{"bd6943a874e9f7f4fec59af5124f61b6"sv, "ea80014b26ca92ebb7755a72b70fc8c6"sv}, // auto-generated
        Param{"36448a30951911e263cdedb84eb9ba85"sv, "3a724ef2934697372e254dcb402d1345"sv}, // auto-generated
        Param{"76cdc13e36f2b29fdc56c87c074ef6b6"sv, "fc30763b563aff093c79aefc3181fe23"sv}, // auto-generated
        Param{"946d9907ae25da960ba8ad8411c30721"sv, "f10e7f2ef6ce5cedab05715c9af5213f"sv}, // auto-generated
        Param{"af68df01a7af01c3971a08ddb43c245a"sv, "bf5da4294c9cd01e44c0173c46fa4a63"sv}, // auto-generated
        Param{"f8ea8a35bf04a54fa7e557708616516d"sv, "645e7eb82918e53317702e9afd2132a0"sv}, // auto-generated
        Param{"6fddedfb6a1a5abe08deb06e4e4d73a6"sv, "f36fc21c7d3b2766b42e022786825f9f"sv}, // auto-generated
        Param{"e5d981327f7472719982fa04013c5782"sv, "7eb7940bd9c4655e159158902cecde55"sv}, // auto-generated
        Param{"d948738465f7b64a704f53d26baea58b"sv, "3df404cdcac4138d710fe127dac822ed"sv}, // auto-generated
        Param{"d378abf91b091dd4d5feba4d05a42717"sv, "7f51edc76a1f9f6c3d12922bc8c6738d"sv}, // auto-generated
        Param{"35110b3ae0fc46be6a3213517c4ba248"sv, "7c2e88371c70ce4bc8562e738540615b"sv}, // auto-generated
        Param{"24524eb8dc0ce2b64d165467825808e0"sv, "80622ddd43dc75cffdb2322bc86dee60"sv}, // auto-generated
        Param{"dc470593434f54e549fe1e8e989a6cab"sv, "f0a7305206fdba37687cc0010cd4f00e"sv}, // auto-generated
        Param{"7d3b6c50576445dc7d9611e272f9fb1b"sv, "7e42759c93ee33dfbc469eee57825431"sv}, // auto-generated
        Param{"8f8b11336a45ab47ba8e62809e4e4057"sv, "cd2cd518d351e6e3cbdafeb27f7aa6a9"sv}, // auto-generated
        Param{"9ce3d77a26260e04e69e17b7fa7e7cd9"sv, "a81ef9683e4587a326f539af7dc9fae6"sv}, // auto-generated
        Param{"c50f5936089e76999e66c951dc8135e1"sv, "79e9c0419f601871e3a2eff760815a92"sv}, // auto-generated
        Param{"9c681f04572025b67b007b28828296cd"sv, "f4964d8e335e019059a639c71cd8d695"sv}, // auto-generated
        Param{"f2eca060f3c5bd99b8fc9af25296d1e3"sv, "a7589cd2a404ffd36092bac9334bd4b9"sv}, // auto-generated
        Param{"857f8e8d132cfb6804d9c14b5f3db4fc"sv, "83655480c353ec96b807f238f08bc3f9"sv}, // auto-generated
        Param{"131237659264f4874d433f396862876b"sv, "6a3f40128f76fc6b021e13f07fbe4b2f"sv}, // auto-generated
        Param{"577eb083bbb06615e1fbf838b47c0606"sv, "9b7026748a420572d8189c04536636c5"sv}, // auto-generated
        Param{"adcafe0da2266cce2afe3cbae2653201"sv, "f5212f73d51b6e97117d0710157cfdf4"sv}, // auto-generated
        Param{"095f4fe2856968387d62a1c8d7b56261"sv, "13c0e66fd6e4406c0103876ddc478a21"sv}, // auto-generated
        Param{"15c3dd4a490a83ef74e3f74e6badf225"sv, "9b54ff023c74fc970f095e04f3d2584b"sv}, // auto-generated
        Param{"1b5c85075d774b26d860954b652b707a"sv, "55e4a7b516769ae95a4e8b7ecee49022"sv}, // auto-generated
        Param{"5dc5365253f0717afcd5b7df67d21e98"sv, "84d2dec0a45ef51c8eafdbca5edf5323"sv}, // auto-generated
        Param{"b149125e6aecacf933200bb810461c0b"sv, "a993c0ddb8d8337d3b078c7125e93eba"sv}, // auto-generated
        Param{"dda442ff05153b2cec5e6ab4bc8509c5"sv, "8fe241d46996782032beacac31bb15b5"sv}, // auto-generated
        Param{"ca106c7b048001197305e60138b3e533"sv, "2f6f5d933c3852bca63e0b0abe98cfff"sv}, // auto-generated
        Param{"fb3198dddf3a6ed2853ee2c97112a6ef"sv, "d8a6d492130f05f83beab9fbf6af4540"sv}, // auto-generated
        Param{"6fb75cf9da32cc4bec16344e29441d3d"sv, "9d2c4def0a46d92e25eaef82a69bf9db"sv}, // auto-generated
        Param{"7f3f1b5bb230dc4a7cfa274da1a4f0ca"sv, "34f965a7e42f9d5a71a9fe1037e4e12e"sv}, // auto-generated
        Param{"2e8cb2f223a8709a05c3317ae97ebc9c"sv, "13a7d74e121b92878169038b9e68fe80"sv}, // auto-generated
        Param{"d47afb16ecf44b2d17202316a845b8e0"sv, "320cba3f3c3d29f753dde44d75b75bca"sv}, // auto-generated
        Param{"8a5cbc80de069cd5e9bbb3edfbff8ffc"sv, "2cf0e2d8d8834895e3d7db4487120f39"sv}, // auto-generated
        Param{"5add7a6e3fd003191cf9ddf681b8a58f"sv, "d4cffaf71593aab790b25b786735ebd9"sv}, // auto-generated
        Param{"66c294cd183fadc14de98a0fa4006e8c"sv, "075054c285e2085201141dcf44238de2"sv}, // auto-generated
        Param{"ee6d029c2e7ccf0b88af1ea7916e2bbd"sv, "ff66035ecb561fe2a8434cf3722c3ce7"sv}, // auto-generated
        Param{"2600c1be4907a4b5fbbda4e2712a09a4"sv, "b8e9f5ed7dbdb144a688799b777e54ee"sv}, // auto-generated
        Param{"00b24a2b03ff9e30e9256e56ddf574a3"sv, "f3d7cb9a9c5b2551bd2bb530310711a9"sv}, // auto-generated
        Param{"639f1511e790d8f3dd1870dbffd74d1b"sv, "e95d1cf5a4e05da325a6a08f49108f6a"sv}, // auto-generated
        Param{"3b1b98b50d5a3f87e232f1517eb5c628"sv, "4150c45f7518ebcdc1eed4b01b54e46c"sv}, // auto-generated
        Param{"b9a1a6b6c6c08b79a2d885c594929a27"sv, "b5da369f516a06f19a1d1061c2e9e162"sv}, // auto-generated
        Param{"8af9722b36b65514fe1b9c4df6144632"sv, "92e9800691ed57f3a95071d50b7ba53e"sv}, // auto-generated
        Param{"d283642452a64e9629cb67654df9e978"sv, "c7af8891b1139733842fe16b4d397c8d"sv}, // auto-generated
        Param{"c07dc8fa3a62b720fce4854b61e7256b"sv, "8a51430087f4df1a4665d950895d60e8"sv}, // auto-generated
        Param{"019e6d552ea620e37c781cb088e545aa"sv, "b2fafcae152660e77c1b864035ed01c2"sv}, // auto-generated
        Param{"50129c0db5208a5245318f0121ab584d"sv, "820150f5ad19fd265f1d194c5c2047ef"sv}, // auto-generated
        Param{"6b5662aacbcfa8c9fb4c3c8d1fd757c3"sv, "bf9386be7a16d5b9cbb03fb08ff639e1"sv}, // auto-generated
        Param{"8122e2e82a240156ccf891f749d89323"sv, "5906258b649bc4bb48655ea388409b43"sv}, // auto-generated
        Param{"11b7f797dbbd2bca92a6fad60dddfa30"sv, "e4d7cbb4405dcf4d9c96ffcaa4d49f01"sv}, // auto-generated
        Param{"63840182e3d718c6977b6fb05dfd8d18"sv, "874bbe022d49f12f8c4705a41d743d41"sv}, // auto-generated
        Param{"d3b4346d45d9164b04981f0cc8dd9dbd"sv, "89237f7bf6f1c0eff917021e1fe68124"sv}, // auto-generated
        Param{"0fe5eb6bb10a05264e20e6edeaa45b2e"sv, "04c77c36f7184ba2d4394f31059372e9"sv}, // auto-generated
        Param{"96f661709f1a892b5755759c3e1277b3"sv, "2ba92cabf85d7839f30fe1909e7c3ef8"sv}, // auto-generated
        Param{"83f4aaf54217b912aadb6c5b5731cfa8"sv, "07e6db94fd4c7be428168c665b0991b9"sv}, // auto-generated
        Param{"b5146967120ad16bd70da44e885ec58c"sv, "bfbcf621e10b62fc9d5e5c3094b546a7"sv}, // auto-generated
        Param{"bd9c149eb54ba0aea6cbb7a02881a101"sv, "f7c0a094dbca356f0affe12a0514019b"sv}, // auto-generated
        Param{"6f42da23679b90094dc2a7764d94b2de"sv, "49d118ff49a9fe5d21c325fcf3095612"sv}, // auto-generated
        Param{"e0613fe777f041a7f6df5da0ef4cf78f"sv, "d106054e4a9fd688c6cae5634da02b7d"sv}, // auto-generated
        Param{"e96c069a8d1dcb32e16be00eeef63f2e"sv, "3272ad797dcd19df9cbaed1cf6199895"sv}, // auto-generated
        Param{"3c02ea8f941bb0788eed36eb66716f1f"sv, "f6198a0183903db7bb5872fbc67dd608"sv}, // auto-generated
        Param{"0487b9daf80ee39c00a4c775cb4867f2"sv, "567ab6005ec157b4d8a0759459276728"sv}, // auto-generated
        Param{"8cd838293b6a620f94d1d8111292b19e"sv, "263f32c9c1712fbb0bde603b899d1e4a"sv}, // auto-generated
        Param{"c42865583ff145eeb49f54f7e2033da1"sv, "62b0c2d3c29c21ec31c97636772ee152"sv}, // auto-generated
        Param{"89ec712023382cbda69a7a0ef26b05da"sv, "ad054fc152e4719ba26224076ce9fa03"sv}, // auto-generated
        Param{"3d66db088db657135068bd06cf04a4d4"sv, "35799497fb3a1b3c0c5af7b0fd98f548"sv}, // auto-generated
        Param{"325a29725550e6db12e24aa24534da7d"sv, "5192830f81ed6b84a78da2473fb752e9"sv}, // auto-generated
        Param{"899d6a6b7952a9e613b526a377f0fdee"sv, "d962ff57d94ac3963c9e788fc4da62ca"sv}, // auto-generated
        Param{"a87cc9dc2725b863adac59b16a7aa75a"sv, "435a0266c4b9e9e6f80376574321f957"sv}, // auto-generated
        Param{"5c706ab6b6ff37db3c8cbc4445d0da51"sv, "97bfb9a99f32b97e3fbb4a78cfbaefbf"sv}, // auto-generated
        Param{"85135d883ae1f29634620d190884235b"sv, "4d82cc7989ccd20d5752ea00f9a5be2e"sv}, // auto-generated
        Param{"5ac776a8d12e5ada9ace2e6114e6a334"sv, "4153cfa1d97b218e4b8a09ad8e17f0fc"sv}, // auto-generated
        Param{"6ea0e533d11577c5a6ad1de7d8d9d0ec"sv, "fb16945e5c42b7d8f52004b6a68d6abf"sv}, // auto-generated
        Param{"68d31b6addc1f8eb7d50f7ce4a7ef0c1"sv, "6c2dba0f4b3de2f499e7e4aad394d28a"sv}, // auto-generated
        Param{"d1993ce1d633845fc0fd2006bd89378f"sv, "6bebfe96b7039f42b9cf05ff601c6ac8"sv}, // auto-generated
        Param{"4255ecdf5224b8ee7b523d0c8be7df8f"sv, "f7bd0b3afa26a7d8b3e8dd241c1ffd77"sv}, // auto-generated
        Param{"822bfe0d9d1700b41eeee5c05a9efb8f"sv, "22fe361c871585f369c33b5dc32d469f"sv}, // auto-generated
        Param{"cc0f0d589ad7b71c7e86e2c0d2c95d48"sv, "a98e7f3d0dd846349dd511d850488ebe"sv}, // auto-generated
        Param{"da3c72bfd2b64d44612da94649f82c21"sv, "bcd9f4718174feab8762d5bcf71edb9d"sv}, // auto-generated
        Param{"81139ed7695112f0ba100a15474c9bc6"sv, "8b26883eb20beda8e9acbd304569042d"sv} // auto-generated
        ));
