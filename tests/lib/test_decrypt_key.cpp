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
        Param{"40a2e0a7cd5ae21dfdf52214e308de85"sv, "3129e3dbc968f253ef44d8003d41b640"sv}, // auto-generated
        Param{"b951fe95cae8020b5a94db1f3d13a714"sv, "af9ceb43da745697a9e88c05506d3473"sv}, // auto-generated
        Param{"b4ca9272f64188d1e19d0b02a26185f8"sv, "e1ccbf8c3aefc4012018a4a29c87b5dc"sv}, // auto-generated
        Param{"4025d4105f2b7fc1f17bd07ee272915d"sv, "5e53570aef9322356ca6615728c0b12a"sv}, // auto-generated
        Param{"baa70373b944769cc437f865c6cd4f45"sv, "14893b184f6d4cc806e119852411d9f8"sv}, // auto-generated
        Param{"0eea316a4a7a46529d186317e50660a0"sv, "60fc5c2c5d73c69226016fa88a4f0895"sv}, // auto-generated
        Param{"b599cdfc27771951b893aac194ab2c58"sv, "575f792e37ff498a283e106c045125b2"sv}, // auto-generated
        Param{"6a1051430e51d5821907f8ac04073efd"sv, "8a924e373d72443fbcd8829cd5297ca4"sv}, // auto-generated
        Param{"71f443c606b38082f6d8ca4cca775101"sv, "c8aa20240ac73b1e70f05b52a1c50d7b"sv}, // auto-generated
        Param{"c0b6c6b9508049a63cf922bb7b23a522"sv, "5ed2a63cce67893f0a272a0a6f63d75d"sv}, // auto-generated
        Param{"2987f49fd082c63256cd766281e54f87"sv, "c9d4bc02296c3940f5eda4ccde932ba2"sv}, // auto-generated
        Param{"49355364e0d06619a6c31d2c70612d23"sv, "c7ff59756572152cf57600003dedf3dc"sv}, // auto-generated
        Param{"4c2d3062abe56eff16f148a43bdc10a5"sv, "ddbff2c65360fa1c824ff63da344d055"sv}, // auto-generated
        Param{"b63b1c79e4ebc7e0229ff7c6ccb81f98"sv, "eb581207950c887d75e3a6d8ab028c38"sv}, // auto-generated
        Param{"fcef215ace14d3f6c27189fe31a7dfc2"sv, "76c8100214dfd4306dca9a1ac0a34f21"sv}, // auto-generated
        Param{"19ef4ca679e34a655cd571193198a8a3"sv, "8365c88f6afab1fab4eb5d529b7e5c23"sv}, // auto-generated
        Param{"66a06d70d70d1f3311dd3f27dcea5682"sv, "ea10689c4b61025f262953ed89142124"sv}, // auto-generated
        Param{"980b3c4a39f55238ef04aec882879ff7"sv, "e1f81c0ca86afe76a8876885435e98c4"sv}, // auto-generated
        Param{"329ba6c350b8168cb39ca81c5737b3ee"sv, "93e27197a35e7e225886d4fbc97057bf"sv}, // auto-generated
        Param{"12e03f7db859abd4fbcd4981ea7be5d6"sv, "ffd5e9cb3e7226eaceabf2fb0b078577"sv}, // auto-generated
        Param{"6b2c7fcd8af754f4c1a0f3dcccadbf1f"sv, "809e663ff50aa15cb6322bcd95094557"sv}, // auto-generated
        Param{"857fff7162f03292c5fe8b8bf7baadbf"sv, "6045d73cea69079ba8ee1d68a4053185"sv}, // auto-generated
        Param{"661fb2941b65e3257d623ed7dc77a095"sv, "c650f077505bcf3454727a0a33e90181"sv}, // auto-generated
        Param{"6f1fb036529b678e726b31cdb1580b66"sv, "f97a6b9fb7a1445ddcceec2096072860"sv}, // auto-generated
        Param{"229e161492609a978510e8dda6bc4906"sv, "555ef43f9d6fe4991f4ceff97a86824d"sv}, // auto-generated
        Param{"2d33feb5c688c228be82b52d4f7fab2a"sv, "9a8d3e5e4d4965d7f7b0c2598c302853"sv}, // auto-generated
        Param{"af5e8a76e01db9a92382254d089a50e5"sv, "3d7836b30c817bb01e8b9372ff3e15a6"sv}, // auto-generated
        Param{"21e524e6a4d68d67ccefb979a64010de"sv, "96707cb473819385ad2170c490af7559"sv}, // auto-generated
        Param{"1a7fdf87e5bcc095580072106080f887"sv, "a350e62a4973eb6b02c7fa5a39bcadde"sv}, // auto-generated
        Param{"0e0c68f85ef190266b575c3d7a8f1f03"sv, "8e0e60a6b9bc7116ec99487e1939e596"sv}, // auto-generated
        Param{"4fd8779d228604159579e8b79a74b0e7"sv, "fdbacb9daf002bf92383c3564bb5682c"sv}, // auto-generated
        Param{"fce0e6d566f0f779d3fb4c2d36accd69"sv, "acaf486174eb6956cadb7c8a0a10aa91"sv}, // auto-generated
        Param{"70e04885aeec3a760592ebf543b9aca1"sv, "f549eceb2170431583b93a79856af346"sv}, // auto-generated
        Param{"f45b5dbb65715055ed62d7a84862dc85"sv, "c40fe0fdb735ebfb84c728a1f21cb3d6"sv}, // auto-generated
        Param{"42f8132a50a8acd88dddddbc150c0f73"sv, "2eeefe4c559066419ab50bc8339b6022"sv}, // auto-generated
        Param{"ad8e7285f11c74fc6c86a615e14b8697"sv, "2b6375d202f906393178c1ab0ecdef40"sv}, // auto-generated
        Param{"b7566d63725c29921decb7a87ae45fb7"sv, "cf64284ff811f9ab984ea5b2d178173b"sv}, // auto-generated
        Param{"da60a6aab6c8875d775a7c9776e3122b"sv, "112949aab5d7912f72ec325685fd416a"sv}, // auto-generated
        Param{"c30df235af8e31655e9e36fa29a2c942"sv, "a17727566632eacb7e4ea84db9cd34e5"sv}, // auto-generated
        Param{"7be7771ef03e54e2c08ffdc3dd084646"sv, "a372c9e7c873285449d2afc4f981ca38"sv}, // auto-generated
        Param{"ea43e4db37dfb17a69d43b1e97ff5d21"sv, "36f95667ce4f89d049779287c0238c73"sv}, // auto-generated
        Param{"b41ef5d119b050127a709b04107bf266"sv, "176be0374c5c5fffbfda0f345abf0640"sv}, // auto-generated
        Param{"8d17ad9d36d912e182dd473ea608ede0"sv, "70488dd66b61b591f6e906bef79766d2"sv}, // auto-generated
        Param{"0e96f547a598937fed973fbb14aa092b"sv, "c49f6368ab5208d950c4d7322c3e9b46"sv}, // auto-generated
        Param{"d6f83436204e70b5634eb38aeaf103b7"sv, "e61fff15221037ca0178d95750b8d321"sv}, // auto-generated
        Param{"d93f8fb360821dc5ee3bacdb4233d9d5"sv, "bc21a31187a5db7ba426b406d99f8938"sv}, // auto-generated
        Param{"2ca194434d3c9066a1be4e60f35a8586"sv, "327536ef396f196995383b35a56812d8"sv}, // auto-generated
        Param{"3441d801a4cd22add5c3aab3449bd339"sv, "ab27a32a40411eb3eaa94b573de8e72b"sv}, // auto-generated
        Param{"79cad9c6be1333821f73e9c6e4106388"sv, "d926099ae3a6d392e625f1c03af47792"sv}, // auto-generated
        Param{"a2bce5b307834f4f2cb758cce4c6c12c"sv, "25a2e7c3490a819fe643d8d0e5b3ca66"sv}, // auto-generated
        Param{"b73e4eb2a93880a6ed08400cdbe4752e"sv, "7a75ce4ee4bd44026211f49bfa77d666"sv}, // auto-generated
        Param{"94bff60e268b94ada7abebe152433cd7"sv, "0d6eb4b7c83d1a402043abf3e5a0b4a9"sv}, // auto-generated
        Param{"5365d5e891b15e24fb7ca335d0daa6ec"sv, "1d99d1cfa32b0a7e27f7714e480fd887"sv}, // auto-generated
        Param{"6f179a65fe12eceedc7a795a60be02e5"sv, "55d25ab4a82394ac8507ba44a8eaddc7"sv}, // auto-generated
        Param{"c8a9e1a82460a59272225d35586f2b14"sv, "f8310a18d31991dc8556139dcd58ea3e"sv}, // auto-generated
        Param{"3c68c38320eec19722f7702bf7de7bb2"sv, "81b1c3f7d896e9192a360dfcfcfde407"sv}, // auto-generated
        Param{"21f5fd5938c6711e3db334515b1c953d"sv, "53559730587a81ecc55357d0fe37a41b"sv}, // auto-generated
        Param{"ce8a9e6386ea6fbee736e82d35788623"sv, "44a1b5d9f95ecd5435dc6420ac23a0e6"sv}, // auto-generated
        Param{"8cbd5f8a050cf73ae868a6b11c870f8e"sv, "ba31e2aff71a014d3e0539c1df8c0357"sv}, // auto-generated
        Param{"a270445b5acda78d6787b3e59852ca3c"sv, "32116f934d9dc673dfb4f797d3656a5f"sv}, // auto-generated
        Param{"a1ff075fa951d246c900ec2a7ff8ceb9"sv, "a00159449cc8a60e8d14bf171a0c50ef"sv}, // auto-generated
        Param{"7e3a2ef3d9a2c62d18e592849d740d3b"sv, "22fd77ea970be2a4f70d7132b0813505"sv}, // auto-generated
        Param{"503f65523e0ae5c43e559f918e832bed"sv, "0b38de7b5efce7e2613fd57da6b7bfcf"sv}, // auto-generated
        Param{"b33c75a74b90f26f60b838149db36168"sv, "f3211f4bc0d9f8b9f6e17b9165b2a0a6"sv}, // auto-generated
        Param{"5e16fa34156291d84ea048d4c6e4e9c1"sv, "501edb5e3c1691060305f5aa9350d387"sv}, // auto-generated
        Param{"6439cf4e6b39cd31348b17a8a18abd2a"sv, "081588c1b4f582fc4b16acfc880c6192"sv}, // auto-generated
        Param{"44992de55656a2b22de9a07bd0b2fe65"sv, "ef10f7df99010b34a29fa947d9130faa"sv}, // auto-generated
        Param{"e7508db632d7afaf91080c879024840a"sv, "cdeb335f9787803f504e31825287a7bd"sv}, // auto-generated
        Param{"3ff518d0780f329f7fc360034a42355a"sv, "7b588459b29ea5ce59bd61212b5c6dff"sv}, // auto-generated
        Param{"01f975c3355cf52eb973df752daa679d"sv, "f680bf476a5a9c7846a6762806990e87"sv}, // auto-generated
        Param{"39c3c57e4c5dfd9a1eec5f710afd67e0"sv, "a37a2786b4a0d865202b26aa4f2fb2f2"sv}, // auto-generated
        Param{"590a9ea9c8ee58eb41f67bebbf9a2cf8"sv, "9439d432cb5ee42e6735460cebc2bc02"sv}, // auto-generated
        Param{"b18a80132689d99e9e1f47adfb763d4f"sv, "030f429ea58c64ecd6eba9c5a60b5643"sv}, // auto-generated
        Param{"c952738ec3efab2b67c1cae50d8fa9ab"sv, "edabf27b4e1efbe595bb03e72da7d3a0"sv}, // auto-generated
        Param{"75ce18fc74527b3b5294fc5745ce8e7b"sv, "7da7f100f2f8d87a73c76c787520cea6"sv}, // auto-generated
        Param{"84783d16dfefb3655d3afc184f461ae7"sv, "785070a1ba4aa482944efff204a98132"sv}, // auto-generated
        Param{"5d314d9f93de20ff9127cf1428164e1a"sv, "fd5a0ee217278c57470bf4d0f87368d0"sv}, // auto-generated
        Param{"32f20cf7602c508f83019fcfda6cfa4d"sv, "4c2182603f50f8ba9a19325baa13ff1c"sv}, // auto-generated
        Param{"f0438297e634fed5d058979c051259c1"sv, "413847a3739e33eccc4f958e12620239"sv}, // auto-generated
        Param{"246215d78e31cdb38f798e6fd5b4efe5"sv, "b2c3f50c2b4fb942001b2673ea8b2bd1"sv}, // auto-generated
        Param{"dbbabba5dc0ca98ba9e53f77ed9f3205"sv, "cee30bfbdbbc4415af303eeed274e710"sv}, // auto-generated
        Param{"ebcd03bae7b02ecd0a2fa1f4009dd5da"sv, "85d479ce5856d83a19041762830baadd"sv}, // auto-generated
        Param{"2a3ee0b8e6324ac71ef19a248d0e5cce"sv, "6294c6fc2426acd4d9e3065d17454cfd"sv}, // auto-generated
        Param{"1b35778a60ab8a5e31e88bc456ab70d6"sv, "2758c781af3d1c8438a6832b46b02c54"sv}, // auto-generated
        Param{"9adb3ca783b9ba14dcd5b13a1d13716b"sv, "dc6312bad9aff11aa151ab4c46c530d8"sv}, // auto-generated
        Param{"59f03969eb09a4452ff1b7b40a8600cd"sv, "c99a454c7a34ead4aa5cc521fc824dab"sv}, // auto-generated
        Param{"8c2af5fff6f1a440476e8bd49a1693dc"sv, "5b1931b736ce3e873b51bb5e45d7911d"sv}, // auto-generated
        Param{"afa84b2c56c5c2427c53cbb0b70fd8f8"sv, "f2b487fbdc58900a048c33bb05717f95"sv}, // auto-generated
        Param{"368b57a0e8f448197c226fb942e0b6fb"sv, "eb940ff5efd6ce9fc5e1a9d259a3ec8d"sv}, // auto-generated
        Param{"ec0e4cbdacba1b5d7adbc576a69b2831"sv, "837d29b29411c9894ee4dfabcfc4c416"sv}, // auto-generated
        Param{"87495ed7e6cd6eda9ceeabd98f76e4c9"sv, "d5f50d3758f884e016970d838c6d9480"sv}, // auto-generated
        Param{"949b7e22606f005323b5358db33a0119"sv, "2c284e14f078adaee4ff83c959714de0"sv}, // auto-generated
        Param{"70135c0101e34ccff4bbf1d73a4e826d"sv, "625bc07bc2e3d6733a397690707a75a6"sv}, // auto-generated
        Param{"cfcc39ec2d3014311e24d325bab9950f"sv, "8c4cad65acca9ac17a6369f0a1ec7170"sv}, // auto-generated
        Param{"7c1933017398b0ed65117e956015bcc1"sv, "4021ebcb9e6018e9a53688b2e6d3aed9"sv}, // auto-generated
        Param{"e2e028af158c55e571fa9e09f27ee164"sv, "6286114158f2ab0c96729b54b540f9b8"sv}, // auto-generated
        Param{"68c02f2cd235b91fad6f6d424d07609b"sv, "bc4788ff71cfcf9b20041a9b59323a3f"sv}, // auto-generated
        Param{"4c4d114c45c38d86ebba3e9ad94a7ed7"sv, "829a4c7b2e562054912492fa1bc5c9bd"sv}, // auto-generated
        Param{"ad5baab31decb4d3698dcaa3730009f6"sv, "295c4103e4019c2033737c4fdf5e3777"sv}, // auto-generated
        Param{"19ea0686ce2e1b3f48f347bd45c346a4"sv, "f4dfc5202ef77e04cbe666298d108152"sv}, // auto-generated
        Param{"8bc6c79e2f6313e48c401fce33ec5986"sv, "4c5908aabf6045a795218ff2e4a245e8"sv}, // auto-generated
        Param{"69cc9aac40c61a562a4bddf337fdc335"sv, "5391b1863fe46732cbc574ffd2e09b3a"sv}, // auto-generated
        Param{"6ae4e80934ab71009cd8a0b5a2ccdc08"sv, "f5cf4c9a66c3b8325a52c0be9e9e098c"sv}, // auto-generated
        Param{"e929816fdb434dab6c98ff31e9a8fbaa"sv, "21b5fb2ea0253ab2b4658233a7d1c787"sv}, // auto-generated
        Param{"61e2a536bfd07cb6afa29665409cebf2"sv, "4a45c69a7719632bc2ef1dc15f0dd8ac"sv}, // auto-generated
        Param{"d7e34561ac81d9e45f965861391b67ef"sv, "f027f36c8a107a4cd8efc53b21519851"sv}, // auto-generated
        Param{"cb3881044109ac7e1425ffddeda65e9c"sv, "f9ac2c8d22d3a76cd9d55e5b00083cb2"sv}, // auto-generated
        Param{"a89dd12cc7ab2497d2bacff9c8aad225"sv, "4a3e069932c693c5db544f361e8ad671"sv}, // auto-generated
        Param{"16b14f8a936076253efbbe87093aaaa9"sv, "5dea690bc326ac0212e2f8746e25728d"sv}, // auto-generated
        Param{"3860be00506a97b836c060905bb16780"sv, "c3df19dfe0146cf2869a3d029d8d4431"sv}, // auto-generated
        Param{"8a6e271a73967ff153247e43f1c8a69c"sv, "a41951d529ba0b45a27aba68fcb14f5e"sv}, // auto-generated
        Param{"2347c27e62abc85e7c93bc2a2fc134ab"sv, "a3cd978b473b6b60886b9c9bbff3e97d"sv}, // auto-generated
        Param{"8f355b5db72ecf790dc63702341447c1"sv, "803886df8d2634c085b7f9f3db74d7dd"sv}, // auto-generated
        Param{"c56d3b0e86200e0d8e86080ed5cbe666"sv, "43eff1b88d41083362398eec7c92ea25"sv}, // auto-generated
        Param{"6d4056045ae39b8495ab7f7e48d795db"sv, "42796b615d1fb2affd0a3d1140ad2859"sv}, // auto-generated
        Param{"97f2985527ebab25446bd0c04cf96abd"sv, "9b97db35a87709d7009197433b2bfeb0"sv}, // auto-generated
        Param{"8a62f613102172266c2b6fae4697f9ca"sv, "3ab4b199c4107cf724d2f8221a06d55f"sv}, // auto-generated
        Param{"00fbdc8ac303a0aabaf02a69cd136fd4"sv, "8b27edd3e634011e675d50f4ed469455"sv}, // auto-generated
        Param{"b98602469b3e262b624516560fc72938"sv, "21e996bd1ac9ca37c70d689ae58b3098"sv}, // auto-generated
        Param{"098712f1ff6632a4535cead5c70b3fed"sv, "1f324e5ae9fec86be7975d2ee4adf184"sv}, // auto-generated
        Param{"f831cd1c2148c910693245a345499e17"sv, "991cb19dde87ad96755129684d0d2e8e"sv}, // auto-generated
        Param{"c392eaf6418dbb5a35dc5b2cfe0e4ed9"sv, "cbf343b57c61802c0320f424ff1d86aa"sv}, // auto-generated
        Param{"b9042c0e3dd24587d7f920ba47c31f8b"sv, "4eacd05d11a737cee5e3de6be80d2c00"sv}, // auto-generated
        Param{"b49434dd2cd41bbcfb4820c395063dab"sv, "022e4927eee7feaf576f7bab363dbf84"sv}, // auto-generated
        Param{"3c1a68874222b73a23ffb754dea80d00"sv, "b2a008cdfc1f75b7d54c520d2f091929"sv}, // auto-generated
        Param{"a7a5f240b77f2cdd506aaddf231e64ce"sv, "fbaf9a6f58f14a9592cabfac9295a76c"sv}, // auto-generated
        Param{"e306eb8af39d21015851520c64240b34"sv, "b751923eeebe97db55e5a96c68a09bf8"sv}, // auto-generated
        Param{"7197564925f4269c88c4cdf58a80b99c"sv, "a79f1686b8a4b284850e22f4b61c8b1d"sv}, // auto-generated
        Param{"400a743424f109784e73e0d622b793a1"sv, "c2c808f147aabc0417336f28c3ad5170"sv}, // auto-generated
        Param{"c38516b8f2d6e931c2806d6cac03bd06"sv, "967e5915e3dade4bb667b7a8c167abc0"sv}, // auto-generated
        Param{"e2964bc34ffcf07673bbc504169bcbf1"sv, "17f16e624e82e4445cd1287465da7dc1"sv}, // auto-generated
        Param{"86ee309896177a3e9ec73cb56f6550cd"sv, "f4223349d4ecc43be15f4bd1e502eb04"sv}, // auto-generated
        Param{"980b6519ed7813b8a551e7e4919a67e6"sv, "fe010822989f98df7a06b0602339e891"sv}, // auto-generated
        Param{"0d720c2544633ceba4f4f2989841453e"sv, "e0acf8e512b12bd4c0b3a1ba89d85ef0"sv}, // auto-generated
        Param{"f6c33db902136d44f1004ab292bfc6d9"sv, "fd49062c82cf3b506b5faf3760fe695e"sv}, // auto-generated
        Param{"198bb391e5d2bca9bf87e3edaa34dd7b"sv, "85652c056d2f5384ddb6f5180eb857aa"sv}, // auto-generated
        Param{"327d64df606a59df3ba601039e27793d"sv, "e0c96753cc362ed2f6459a842106ced2"sv}, // auto-generated
        Param{"ff3a1dea189958299ae3ad7facd5c5de"sv, "949ed3457f6506e39b67012a6916cb8e"sv}, // auto-generated
        Param{"c0e09510bbc4fc6cfca8039a37eb10a4"sv, "1669ebc50a6b834e517c1ecdcf1b93a8"sv}, // auto-generated
        Param{"96573914cb1c78430f566e38852ba5b1"sv, "0dbcf21e7950a63ad9f3bcd77774ac93"sv}, // auto-generated
        Param{"fa9dba531eb2ac6a6668c6f3e61f4914"sv, "b62b004d56da88b1b0d7787c0154d01c"sv}, // auto-generated
        Param{"e9a4c91c1c1f2fa5660333ca45267b41"sv, "80d9e0a1764c26342090900ee51c7004"sv}, // auto-generated
        Param{"413735c590b548ed18395b958177cc83"sv, "9497664950de5e13842aa041edeff275"sv}, // auto-generated
        Param{"b3fe2ceaa4d3f1af7b1fbbe45e9466ad"sv, "8bd3af9f3941c2f1fa58a8308239faa7"sv}, // auto-generated
        Param{"c6012ce229a58819dbfb9de8d0a719b0"sv, "56c3aaf8dd298b255e105a046074b4c0"sv}, // auto-generated
        Param{"cc6dc26ab0e4a9b0e0d3ce30c5bb6047"sv, "778051d0f1b5db3a3924c4e399580ab7"sv}, // auto-generated
        Param{"30902b26ecdd663ff2a040d5eb99b037"sv, "cb96bea6c565e94a46b24cda2bb900d9"sv}, // auto-generated
        Param{"4fce8f90551f4863c7a944506627ae0b"sv, "9bfe63290105262c3c7ef344d72a320e"sv}, // auto-generated
        Param{"5a483e5b6b3c8a0c3286179945271aac"sv, "8bc6e6afaa92737e065127a9446ea257"sv}, // auto-generated
        Param{"63f746258ad0d3f5b4e1d928ffc4c6db"sv, "a4803288469976f65d45fc62a4f368b5"sv} // auto-generated
        ));
