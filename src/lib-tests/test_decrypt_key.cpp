#include <gtest/gtest.h>
#include <unplayplay.hpp>

using namespace std::string_view_literals;

using Param = std::tuple<std::string_view, std::string_view>;
class DecryptKeyFixture : public testing::TestWithParam<Param> { };

TEST_P(DecryptKeyFixture, Unit) {
    const auto [key_basis, expected_view] = GetParam();

    auto decrypted = unplayplay::decrypt_key(unplayplay::util::Key(key_basis));
    auto expected = unplayplay::util::Key(expected_view);

    EXPECT_EQ(decrypted, expected);
}

INSTANTIATE_TEST_SUITE_P( //
    DecryptKey, DecryptKeyFixture,
    ::testing::Values( //
        Param{"8674e0d1d4182d52450badb3d2d73687"sv, "8a5eb16b96d7d666db333af4a783efdf"sv}, // auto-generated
        Param{"c6a74647c5effd07923d224016270133"sv, "1916cb4d69de79217c98dcfe60619ae6"sv}, // auto-generated
        Param{"8aaa82e8893d22a1e634815fa074211c"sv, "8958687ec55465102c95938b720aaf9e"sv}, // auto-generated
        Param{"2b353493a2d029ebb64066954759c814"sv, "5357759a882185b9e807c679ccc144e6"sv}, // auto-generated
        Param{"0df9b166f1d81be48a9d5cf8a75a96bb"sv, "a61596f6787bf9fb36df07c5a341a2dd"sv}, // auto-generated
        Param{"ddf2a75d50d19496ac54290302d31ab8"sv, "893d674ae9e0b44dcf37f7ade6bfb23c"sv}, // auto-generated
        Param{"91a7c1b775af2969320d45baf4562252"sv, "5d78334555bd1d0d39d74cbc5bcc9462"sv}, // auto-generated
        Param{"08cf28c61688eda4f3d6b9b1e24314a7"sv, "e7911a91b89a0ec98cb1e426c48c3597"sv}, // auto-generated
        Param{"d94dbe08509cfa21b1d25b1a6d8428d9"sv, "9614d97ae746ab5434b71ec2b82d2e04"sv}, // auto-generated
        Param{"f3945ad902de98848ecf0b81069f104d"sv, "dd538c205fe32bf66f74201d14b11ba5"sv}, // auto-generated
        Param{"ae999e942f53d1dc7d14b0e844f00a1b"sv, "fee345909aef61c7cbf701f244a83703"sv}, // auto-generated
        Param{"d51fbadc0d88e8be854d370cb3d12051"sv, "b8756b84bd9fd8614a830dcc26245552"sv}, // auto-generated
        Param{"9c85a35e89c68dc8e37c657bb2cddb5c"sv, "45745d378de4be904733d451508ee9ec"sv}, // auto-generated
        Param{"a034419a07119eecf25a19c4ac996eb4"sv, "9c14f4c2494bac4ff235d03ae450ae39"sv}, // auto-generated
        Param{"9d620be1ae010ca072f3a950310a7ac2"sv, "b066a4c3fb696daba9431fa7c4909dfe"sv}, // auto-generated
        Param{"5ccd5604c05de68401c29a478087c558"sv, "51b2cefb248edce4f64808fa6c0dcda2"sv}, // auto-generated
        Param{"ee483e98fa0adb697f4158af46d1b0ec"sv, "76477004aada4c3a2d895b733e4b41d8"sv}, // auto-generated
        Param{"cc660811b56b9d22ac96114724eb6660"sv, "a0b04be9df720869470d3229c51fc3ec"sv}, // auto-generated
        Param{"66e76e1f1f6626283bfc7c02c9b4c6a0"sv, "8f1038f6d170885769c750e0ec23d258"sv}, // auto-generated
        Param{"de6a37b5b2ac74b941429c1f70bc3ef5"sv, "b7f283ce94cd424a4406f810dba84c95"sv}, // auto-generated
        Param{"740493604abb28ab58af109b245cb52f"sv, "6831ab6a9c8a32988104fb1daa098d32"sv}, // auto-generated
        Param{"27c94cb8849de2ed8c24a30fe16435ac"sv, "0e5a42db7c9d9f635c2af0cf6e47ed1c"sv}, // auto-generated
        Param{"67f0709cae4b7b122202ed038eec96d8"sv, "905fcadd2e4206e109d2f0335feb8d0b"sv}, // auto-generated
        Param{"a6f88e5f0f25766a6f58b06d85a082db"sv, "305216a2ec7e00035831c9b566154459"sv}, // auto-generated
        Param{"a5f93b36af961dba78365e02496ad7f4"sv, "4fc36babe3ecae8d47e776272d1f85df"sv}, // auto-generated
        Param{"a3b5a84aaefa387e1c9de1cc17e35d0a"sv, "2a30b737fb8210b2623d42b9bd0ff431"sv}, // auto-generated
        Param{"6cd33f193428ae6b2dd2651e136d16ac"sv, "e4ac9a0f617b8f4babe8e88ec05c6f72"sv}, // auto-generated
        Param{"92a301c7d016ffc365cbd9b479a3673a"sv, "3cbc3282c75c6755bc5650cd156e7ec4"sv}, // auto-generated
        Param{"a5ab2ce144600288759254b358000166"sv, "f84ee5901237b7b455333b2bc3b0f7c4"sv}, // auto-generated
        Param{"87bad7643c675c272e69ff3568396dfb"sv, "de8837873021ff525a9eb3bb73a0bb88"sv}, // auto-generated
        Param{"95869dace896919798a520f2b26b0f07"sv, "0027e38e6217f4d14b56ebee6f76f689"sv}, // auto-generated
        Param{"985eb9702ce0bc7c772d86d3eeb9eb07"sv, "e2714686254d8912d22f131277a6f8ee"sv}, // auto-generated
        Param{"5899e9e3bf5defaa7210f3ae72bd6aab"sv, "184ab4be2882c57b83a00edfdb8c5a65"sv}, // auto-generated
        Param{"f797a18e0f691bc9201febd2375e1b65"sv, "9c7d3154e1f1b6b3b1cf0be2bc6f4406"sv}, // auto-generated
        Param{"be3a86ec35a83d240b0ccf15a6892da7"sv, "990b11e42e3c72824e389b79ad74cf89"sv}, // auto-generated
        Param{"3247a6ef94c880f340d362672109814a"sv, "d0173d0841732e9c787ef31dc2350da7"sv}, // auto-generated
        Param{"622ed0520045828a225445cf8d4de349"sv, "68946d4194694be417b31fbd8ecd1b22"sv}, // auto-generated
        Param{"006332c02419b774ccf78e53a1ceeb0a"sv, "b8f6cd0d6572f166cd7b35f14084cef3"sv}, // auto-generated
        Param{"9c6c705829cc6637860e9f79a7b66c0b"sv, "db21dd50493c226d6640157f6c7075a7"sv}, // auto-generated
        Param{"205fc2ffd3c63e51ae0a4107524896ae"sv, "42d4058ce1de24b41912b1dbffb0d7e8"sv}, // auto-generated
        Param{"44b00305971ed9b269cff402944b07f8"sv, "cea3ceeb8e792f46bfcb37c84f94e4aa"sv}, // auto-generated
        Param{"9761f480736d2704038dc63eb9659810"sv, "220ff224ae2fa399a9c9028f0b75a2f0"sv}, // auto-generated
        Param{"50ccfe8f5b377d0da7c10a39db4583ae"sv, "75d534404bf269d1aea528c3c3892cef"sv}, // auto-generated
        Param{"f768984558c29f1e261e7884fcbaaed8"sv, "43c37167902704b4c34b9f539fa3d570"sv}, // auto-generated
        Param{"aa827c05b619ad01f5391b9eb67f7a4a"sv, "fe303ed9f88a67a2f4984dd7f217345f"sv}, // auto-generated
        Param{"f52e401eda5f6c3c0fc33bc5935ffdfb"sv, "379ef16f09dd2f9ff4684962fd31a353"sv}, // auto-generated
        Param{"05e80fd0368297c94e443d07e411b432"sv, "d3f61f842b3bf1382066bc1aaea403a8"sv}, // auto-generated
        Param{"10f02ec7ab7444d284f4d78a0f58003d"sv, "355474e68e6b8610ef37de97e3df7919"sv}, // auto-generated
        Param{"47e356721f5dc1bc0608b4e95917abad"sv, "ec49c06e97ebc34caf286827fb763324"sv}, // auto-generated
        Param{"8fbf64e7945bc26e33f21903dcad58b4"sv, "4b56f890142375606aa327e7252d9018"sv}, // auto-generated
        Param{"499f4b5981f61c64f4b70f14a409c75d"sv, "5c380da1f6114823aeee6e07f65c19f6"sv}, // auto-generated
        Param{"3e77d1bab5f0e0a4cae1dd55c2ea7f6a"sv, "19556f7b856a0992a5b323c27a242fa5"sv}, // auto-generated
        Param{"6a41e7865ac60295adfe0210b4648381"sv, "3de22c1547ad3e7214f5c0398d06147c"sv}, // auto-generated
        Param{"b0158dbd8ca5c41f8a171029542ea4f7"sv, "a4811a63ecda1de120fa03df23819cc5"sv}, // auto-generated
        Param{"989ebc5265e7c5c1e7c8df518d731e08"sv, "bcff3f37b5dd5281c20c89e58c5c2d09"sv}, // auto-generated
        Param{"4ebe49915be378de97602d5f890ab5e9"sv, "fcdae48fd2870eb5fc07aadb5cecfc4f"sv}, // auto-generated
        Param{"ae9f7c74ce86124eb34e722751f5604e"sv, "98101ce9aa2a8497d8ad33e5f648958a"sv}, // auto-generated
        Param{"1d19114e153a566e1c1fc5c7a35a9ed3"sv, "20b83390d4e38a5ce539c8645d9f3380"sv}, // auto-generated
        Param{"a8d95a3de9aff41a995a034f31f4a031"sv, "8291f8aeaa03c1b6577fbb164772ad9d"sv}, // auto-generated
        Param{"e624ee10d9c533c514d3a7aa47e4c44e"sv, "930bbf5fc08c29d6edf0de58a8745a31"sv}, // auto-generated
        Param{"190bb5060b80631475b1747cb5b6e77d"sv, "657ffb046b807644f8bb48ea1121a909"sv}, // auto-generated
        Param{"b86b1396cbe0857d4813799201f69621"sv, "ce8740a4384d3392b75556215eedefc4"sv}, // auto-generated
        Param{"f774bf071bd62d459626a4b827901bad"sv, "144a5abcf3f0e048b464311223381ea3"sv}, // auto-generated
        Param{"8cee87ffc6649b71fe1fba77cc9312ae"sv, "0865542fd42e82016e8207fb93c166d7"sv}, // auto-generated
        Param{"0d782514337e87a86fe21f737983d792"sv, "f72a4585e80c3d10c9c03e6e9a3e26f4"sv}, // auto-generated
        Param{"2717918b5cb5b3faef77648a136a02a5"sv, "f80792dfd4288c67f2447da4a18079a1"sv}, // auto-generated
        Param{"106456723d2b4a1ed3f437b5a57541e2"sv, "ef5f3cfcd3037ccbf76176ed08a7d0ec"sv}, // auto-generated
        Param{"b3004054f3446d12d3748bfc125114cc"sv, "33104fc82a5d038350185da79e78bd9c"sv}, // auto-generated
        Param{"5d66db98b470bae142136cbbcc3ee39d"sv, "83aa144483c8e9d9cee85a76ed5efb49"sv}, // auto-generated
        Param{"6a21cd3197201cf5c6bb9f3beab7eaf5"sv, "c66b718d896ab0cc48e8570e9d0921c8"sv}, // auto-generated
        Param{"10e51e3ead262990475c5c1a2d09e239"sv, "7db8261b60bed7d922ce8e90517266f3"sv}, // auto-generated
        Param{"30b0df50b5df4a37d3c04a002652e421"sv, "ebb0eb3a948fb05ccbf5a1b65667abe0"sv}, // auto-generated
        Param{"8eb57a61d0c1b765b71d3596dfb3af5d"sv, "ebf111514df57ea9422f00a979bb77cd"sv}, // auto-generated
        Param{"06b6c5895f4f9e4a0d07e378b21747b4"sv, "6f9167005ee68b133d9af894e804b2f4"sv}, // auto-generated
        Param{"31e0ab02ffd2ff02b716ac8f0bec512f"sv, "50cddd1627ee44f891ab1aa85f0f5a01"sv}, // auto-generated
        Param{"d3bf26336e689216d069eb843367ff63"sv, "b22f788656ef4dc79e895eb1506d2b5d"sv}, // auto-generated
        Param{"feb64503f7ba1c37ff326e659796adb3"sv, "8574982a99bcf0281988bda817397b3a"sv}, // auto-generated
        Param{"3e208a5262f1417f3b9ebb7e06a5aa0a"sv, "055f442e13d1a5f7ba62411ebac374ec"sv}, // auto-generated
        Param{"fbcbac5da70be5acbea98a6f3e7e7624"sv, "428e4387fabf84ff8ca0d95e966f726e"sv}, // auto-generated
        Param{"69b957950766d28478f50fd526206d03"sv, "35abc282795498948edde9a193c1b698"sv}, // auto-generated
        Param{"4c12a29635603f1c9f18be60c1378432"sv, "7fb92e71c755c468a09773eeb1fbb223"sv}, // auto-generated
        Param{"bdf6244a27864e08b33915f732779ca7"sv, "080f68bee4902438c5bf37afb5d41182"sv}, // auto-generated
        Param{"bc7d8e45fcd164a6ec1ae46369885d6c"sv, "ee5af64e1227876bb6309042ce232fb2"sv}, // auto-generated
        Param{"04c20f04c503651206ed8ef180db7bdc"sv, "d032e68c4cf83588af14397a26967adb"sv}, // auto-generated
        Param{"c22674d6b5e05b86838d2cd32364458b"sv, "6bd9bd4ae1eb5f1bad9393de214459a1"sv}, // auto-generated
        Param{"9100be2b1ab83c152a8e6aabcbbd464c"sv, "37361faaa820ebac804f58f832f05e8c"sv}, // auto-generated
        Param{"7f0cd22957dcc778cfe8944293dcff1e"sv, "f6cc11b69d173eb63cce09574702e7c5"sv}, // auto-generated
        Param{"8823ba7c6c2147233e058181378f46d0"sv, "3258e37e90b8722cf5b8faf723b313e6"sv}, // auto-generated
        Param{"3c26e67fb6ab414eaa35a3c72903499a"sv, "5d2dc92b799be7edc6ae4fe81488a684"sv}, // auto-generated
        Param{"7f0963846b8c8114ffacb4c74022343f"sv, "de6bc246b5d42d47d9b26b269e815044"sv}, // auto-generated
        Param{"39e03979430b930de948c94cd2e46f00"sv, "ad663301d454ffcca02d715298313e5d"sv}, // auto-generated
        Param{"bec416767522c635020ab47e748a6851"sv, "0b181d7d42f29418cf8f89678299ec00"sv}, // auto-generated
        Param{"1ba54cbcd0890f73e241d186f1190cb8"sv, "ef0ce22c0054f3adabd4e0ba70bbf0a1"sv}, // auto-generated
        Param{"687c0e812f163e4c2ef4730667b225e9"sv, "8c552c4d9787d30354f0c78c3aa3228c"sv}, // auto-generated
        Param{"9f553afef56adba0bba37934ca7f2221"sv, "d74a5e7247336fbda9763cd472d27ad9"sv}, // auto-generated
        Param{"1fcaba07957518f85703b5f98d959230"sv, "a0abf316bd6afb8a35116d210f5ad97b"sv}, // auto-generated
        Param{"50592259878057fe4b3d84a2bca72c03"sv, "e5573ca620a818952888a5f711b6d5aa"sv}, // auto-generated
        Param{"48b5d4d04b34b55baa425df2d6a1a46f"sv, "9c587a863f60d5734caea18cef0d350c"sv}, // auto-generated
        Param{"f9b7535ad73e9416e41500a8317dfdb8"sv, "1dff61ebf03fe1d96013471d46319592"sv}, // auto-generated
        Param{"775874fea72b7f1821dcd6f4b524c442"sv, "d360f086a8091c49a9697eb915448390"sv}, // auto-generated
        Param{"3b0981963d341a660fde55e4a76302ea"sv, "87c10f44a3398e3bad0b013ddc0cc1bf"sv}, // auto-generated
        Param{"26075dd585240d948311e6ec64b3e0c5"sv, "1be5cc7625481833e0a6385cdb548098"sv}, // auto-generated
        Param{"7af33ec9c8014475cdd9a23490cedbd7"sv, "91ac2c1b4cea01bc201d2171c239568a"sv}, // auto-generated
        Param{"2d1a7a975599018e1f4e95301c8ed375"sv, "9512fe4f40ad135cb813f5a7a2cc5f3a"sv}, // auto-generated
        Param{"6def6627eb52786a07a60eb857018b54"sv, "d1c9d93fd8290c84010999a5bc8b8899"sv}, // auto-generated
        Param{"3cb1772fbe1acbbd1b33a733b648b108"sv, "2f3e740acf25876733d4556bd12535f4"sv}, // auto-generated
        Param{"26fbdfeb1ef9156b65485e9a6afbf59c"sv, "c80a3acf91d21e6e000871a987bc8556"sv}, // auto-generated
        Param{"4180a366c98e12ec0c241f187a704974"sv, "4de4a88896ee59224aacc06d151027ea"sv}, // auto-generated
        Param{"e115facf1e8e37c53183c6fbb71241b7"sv, "2a98f5f152094953391d38c3804d5a1c"sv}, // auto-generated
        Param{"b7aef785125278e8ae59da74918f12b7"sv, "4031de2f83fc1ace4b30a475718c4fba"sv}, // auto-generated
        Param{"90a3824d906e9385809f9649643cfc54"sv, "8299c0a23d23a733845b663f82164c4e"sv}, // auto-generated
        Param{"25b7629ba343c576446375dc054a05c0"sv, "e783e3dfb572b87bc80770faceb08ee3"sv}, // auto-generated
        Param{"d2fb01aa6c0a3269f7ce5d7cff802945"sv, "bf6fbe44992b4967fccf2e5762a21c0c"sv}, // auto-generated
        Param{"045232e019c349eca01ac10edcd624f9"sv, "97957e2f106ea04932819417f90d4c54"sv}, // auto-generated
        Param{"616e175a68e2573a01fbc92f2cf12198"sv, "c21e586f7ab41093195f9b50ba613079"sv}, // auto-generated
        Param{"e9f37670f6f4a754195dd11928d9463a"sv, "0717029def12ed917ec1c24ddf259dcc"sv}, // auto-generated
        Param{"0732f6b333d61c7bbdb12db9d5ad75f3"sv, "978a76dd16dd8426138d0a9e8258aede"sv}, // auto-generated
        Param{"7796a55bc953bc39199a48bada37ccdd"sv, "43ce26c0868821adce2f467008c382d5"sv}, // auto-generated
        Param{"f4a3497b3a6bdce18e160ede4be10f60"sv, "9676eec205cc2b33eee5389c5e1029c1"sv}, // auto-generated
        Param{"0523dd76727be051003afa2de4c1c52b"sv, "7be57600eb1175cd620796541327b37c"sv}, // auto-generated
        Param{"a4c69c5116d67d8a782377271ebfb413"sv, "0f4e7dfa5bf0f0114cd3776c0a112903"sv}, // auto-generated
        Param{"510cc8ce12d1e762ecb6b67f870ecca7"sv, "7e3faee45fde43022025bf15a430e5c4"sv}, // auto-generated
        Param{"202af77006323ec5cb8d60eb1f75f081"sv, "750890fd30f529e8ba39bf6e950c49ef"sv}, // auto-generated
        Param{"53c43cc4e26a1bd5cdea09622d48e6cb"sv, "4378369534e6d56019b9f8cb76d6363b"sv}, // auto-generated
        Param{"50d76dd116fcc820c5cf25e36a20ab69"sv, "88b88fc60a3738aad76bde4459968de2"sv}, // auto-generated
        Param{"a5d9a57f80c9ab459c072a165a2e233e"sv, "f35f402e84dd9f38e96accc02e3cbc9d"sv}, // auto-generated
        Param{"869dc7d5ef4f5ce2f8f2ffe86e33693c"sv, "a49ce8fad648582e4c4e0223bf40445b"sv}, // auto-generated
        Param{"18682ac09ff8965277fbd581003e4766"sv, "2aab35915acade6e85c4b00bed9a1a4a"sv}, // auto-generated
        Param{"23d3c35289613a740f75a606fbeb4eb1"sv, "177a3a26f9aaca59416aac8228807a27"sv}, // auto-generated
        Param{"101a37c851acaa04770d9ee9176e1e94"sv, "dc9aff581c065e163fbc1f535c19bc4d"sv}, // auto-generated
        Param{"66d29dddc0acd3ce4e112e64dd27f0c3"sv, "b6e20236e05a512239a4d1dfb96f706d"sv}, // auto-generated
        Param{"104fa0efda2739c7ceaf79be26f3034a"sv, "0ef89c563ee1aaa1258fa4de8131a909"sv}, // auto-generated
        Param{"bc617d6b2c1b11ae693c91a0f5f2a3ef"sv, "3944c0d886d1325cdb4a1ffa3414c859"sv}, // auto-generated
        Param{"3265f10319603b31dd622a60cecdb79a"sv, "c86f433f036836f6af4af268997a0189"sv}, // auto-generated
        Param{"eff96f128576a3c5d72df727fa6811e0"sv, "8f65d5d3898601214e514831093a4a1c"sv}, // auto-generated
        Param{"96124fd06ed6568082af573c6d6bb474"sv, "3426e7b56b314c8e550da3da4cbeea2b"sv}, // auto-generated
        Param{"4d223d8c7801ce9f43c08a5d4a05425c"sv, "a4d39da6ec0e668534006ffaa129dc28"sv}, // auto-generated
        Param{"efb3eb0e409e9c705607524a22305fb3"sv, "168b6349b6f4715d65c24068709d3257"sv}, // auto-generated
        Param{"b72cb190b8a4baaeac9e64fa24d5ae8b"sv, "96db50cdc1229a8513aa2dd21035c8a6"sv}, // auto-generated
        Param{"a0a9fa00e75bb6e0da20d5a1686f6cad"sv, "7403390816ec4be6b94256356175e6a7"sv}, // auto-generated
        Param{"6b490bcbcd535cb09923c293ea770236"sv, "4ce0dc7c06b4248593c6c2905fa96a3c"sv}, // auto-generated
        Param{"7bb1e625ba0af2643c20e8a8e8f48097"sv, "752d4c60abb429b2ac3124b14136b29e"sv}, // auto-generated
        Param{"e73851fbc6855ed081de14fe2232857e"sv, "6ac2f05ceca119d3a7c4c32e800e3f66"sv}, // auto-generated
        Param{"c198a655c44ed129a6c23617fac5485c"sv, "29917584421fe230955c037506a0e293"sv}, // auto-generated
        Param{"a8298ecf93ff47e7e5e8066d40477af9"sv, "c71bed43d336ea10808af8d4eabf4486"sv}, // auto-generated
        Param{"228deb17f4aaf62c34d377e456169818"sv, "ac295905ea4e01083a52edf4bc24efd2"sv}, // auto-generated
        Param{"9dc64a2d13d50d2cd186683c73c4aaac"sv, "4919a493b1f43be359e3a6f84085a161"sv}, // auto-generated
        Param{"37eae939fb3373735a76d6764725b3f4"sv, "11feecbfee74219bb93e8f8e945d1ad0"sv}, // auto-generated
        Param{"4ce0d1895036c9ae17ea39b286723f50"sv, "7a597ee754b382b3da16bedbf8a2a86c"sv}, // auto-generated
        Param{"7f8c95092c306645c2c3a19a49a94baf"sv, "295fed9f30fe3ee59662926ef15ea0f6"sv} // auto-generated
        ));
