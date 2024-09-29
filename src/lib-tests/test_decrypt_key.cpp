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
        Param{"c3260ffdf68e9b5b9dc494a52343a698"sv, "0caff9fde4054226aa40f4bbc67318e3"sv}, // auto-generated
        Param{"dc5e03ff36234d7cc5a99ed932b7b1ff"sv, "ccfd736bd0fe3176669b60f3c6ec0c99"sv}, // auto-generated
        Param{"dd2243431e32f5fab98c977f609c74a7"sv, "82d8869b82ba88fc2ab72d3edf4815d0"sv}, // auto-generated
        Param{"2fd17bbe57d4a9225cba28a3ae028e3c"sv, "ea833b4f869ecc63438826a2a4e11296"sv}, // auto-generated
        Param{"1361ec7f339829eabf80505448819b22"sv, "76d449f8d1f54d08f84d0e341e26deeb"sv}, // auto-generated
        Param{"60adbce833596105194e0b5a43c6d4dc"sv, "9a95215b134769366ca202613ff80b40"sv}, // auto-generated
        Param{"d52a86052c4f9cb07643862270bb1599"sv, "5c482df71388867f17f1a06ad9cb99c7"sv}, // auto-generated
        Param{"8f2291ca9c359290aea58e472ea97eaf"sv, "a6172dfcddc84f3581861f6941101b2b"sv}, // auto-generated
        Param{"265ef6d949dad58309b953607eba1dd0"sv, "7a8bd63d9ac4f42f2ce32f1b74bb9d52"sv}, // auto-generated
        Param{"be81c74a2c6b9b53dd21081a7e3b19e2"sv, "06fc7fdc3f68f4d13332c0e8503413b5"sv}, // auto-generated
        Param{"eec62a214e2240897a770acb8f3c00ee"sv, "915a402e9c434855bf011d0684624435"sv}, // auto-generated
        Param{"d58257875b8e90a7020d7e32797d02c1"sv, "6ac679bf630edcbbfff4a608ed701d10"sv}, // auto-generated
        Param{"dfcd90ef566d44da5b572de4bb3293b2"sv, "7a253dc9959eb0ba34a7b563c5a0fd46"sv}, // auto-generated
        Param{"138d01e115e329cf59e2041cbcacfa4a"sv, "8a26d4b164a643434648964a7d0b2418"sv}, // auto-generated
        Param{"75df6ac33848fb9e0457d428a3cd4974"sv, "782685ba74e597045b4811014c4a0b45"sv}, // auto-generated
        Param{"eafcceb111b146c5c81055e3ecaba3f4"sv, "69b2ca09d67b7c8046d68145013cb43f"sv}, // auto-generated
        Param{"132e2d5507023566d38ae98c62867de4"sv, "699f091d12a1adb396a26e60aaf9d8f0"sv}, // auto-generated
        Param{"ee87811487bf771d2d938870736bce38"sv, "2dd257db1b7052688345a38d5dee8987"sv}, // auto-generated
        Param{"0d4c811c1b39c6dd48b51c4da77b36c4"sv, "0622e8043b3e95071dde14a448ed826f"sv}, // auto-generated
        Param{"81f6ad19ddf5fc35a040a4185b053f8e"sv, "a75b0280679c43644044c4ede97f4f10"sv}, // auto-generated
        Param{"efbcbbe818283f2a14222072ee253934"sv, "201a9f12e98cdbdc307761ba97e1c16b"sv}, // auto-generated
        Param{"579bc3c583426bc50b56e8a397052684"sv, "10092428bc9c8034abe22d812908e691"sv}, // auto-generated
        Param{"c5bb9127d5901eb58011efad3eb2188e"sv, "6f5e34c9329aad10fe4d82e7e1a7a43e"sv}, // auto-generated
        Param{"3f390a616e6309f0d6dec848f9be583b"sv, "1e7d7578a25259b41a2fb1cb9c3515a8"sv}, // auto-generated
        Param{"8c7384a02a205b3157deb16c8ff5fbf8"sv, "5b9000efd2dbf27b61db111da518d2f4"sv}, // auto-generated
        Param{"a08be7f79ddfc4934da751479ebc92dc"sv, "b1601ee87d2c4eb3e7488a111493a5eb"sv}, // auto-generated
        Param{"44c870818e4710d323bfa33c6535878e"sv, "a114329b508b3d6f7a4e0d205426ae0c"sv}, // auto-generated
        Param{"334db7289b1f9b1f163862e8e344e47e"sv, "6e172a3f891d0f795014799a234b158d"sv}, // auto-generated
        Param{"57a2ebeda91c9613ae7f7b0be7e7f180"sv, "c89c3dfd593c842bdbb85382464cfb31"sv}, // auto-generated
        Param{"65be3b3d3f954d31ef926a179d944560"sv, "da03f4eab94d23a361bb71c5733b9e93"sv}, // auto-generated
        Param{"1f989c42b58401c5dd17893fc35588cb"sv, "973a4a4b3a77909c331023dd9151f6ec"sv}, // auto-generated
        Param{"f8ab3e8cef34a15dae904fea9b5490d6"sv, "3c3d21a574c6233634475ab251cd37d5"sv}, // auto-generated
        Param{"7627b9bf9c0aed1bb27ffd201d2472dc"sv, "6f5f31a0c5654c5594dc27c6da89ccab"sv}, // auto-generated
        Param{"57693368211126a7ce546b1416bff978"sv, "cb50b5bdbe6dd152cea0ccaf17577436"sv}, // auto-generated
        Param{"f87a50d1ef617651addb84b220002483"sv, "513644a3fe64b9ac7fc237315d235d40"sv}, // auto-generated
        Param{"aceea9c4d310eead35e3d45f4c43d470"sv, "cdac93a2050afdb695b6d85b5e70bcb4"sv}, // auto-generated
        Param{"436a75b8019a2056ee90a9a932c00a82"sv, "ce9075e0d3270b2ceefa2640b9ff653e"sv}, // auto-generated
        Param{"8765db6676967c68d4e1444a5e441807"sv, "231ce12faa4748900bacb672168fb56e"sv}, // auto-generated
        Param{"a245f33bf016fd2a8a9df8065450d245"sv, "b326234e1937db3f87b88720c4cb91d4"sv}, // auto-generated
        Param{"9c5cb8906810caf943c03a3459c2cb9e"sv, "399049767b166ac6516fba2f3678b51a"sv}, // auto-generated
        Param{"30c5550a0f615312291472f51dfc9787"sv, "a2b4f1a1744f9a597bd4719f23651d09"sv}, // auto-generated
        Param{"cbd6c8d5ac002e000ac8213c0e2d8561"sv, "79d39d1c2016c66e28ad1100132a5c6c"sv}, // auto-generated
        Param{"b476d7892c5fbc8e4754ff6c5f01ff46"sv, "80e57dec34071529ffdb483647061d73"sv}, // auto-generated
        Param{"dd488555e6cb6125f293ce3a93de1394"sv, "0b983a0d4a48aeb9b3f69bf04605c62f"sv}, // auto-generated
        Param{"96757e3bbe2fd4df83ed06c737e5717c"sv, "37ee802e2dc7f8440e7376bed024753b"sv}, // auto-generated
        Param{"db988a607451b1375795795862d4d549"sv, "514b817035c4a48a46905b6bd7586529"sv}, // auto-generated
        Param{"6d626de80c9fb7590579cfdb6dd91d6f"sv, "32b42c10e6624143ca9eeb098c247cab"sv}, // auto-generated
        Param{"6958a35604e0b56af666a0398c5d7d3e"sv, "f060774ff6cfd8459eece14913c61166"sv}, // auto-generated
        Param{"7b2a0db17130141f6d2778c177fef32e"sv, "18f1bf4d69f3a35f99f4ee0186708935"sv}, // auto-generated
        Param{"8860874cb37e8e7d08214b7c6c9c66f0"sv, "6df4a6ad48ad616d5beb216bfa32d478"sv}, // auto-generated
        Param{"279a55ffcecf0c86e875700258a88c90"sv, "48cdaac645f0c65f8df9fd58f192c215"sv}, // auto-generated
        Param{"2cd3dc9044fb7c28b941b123618bd4cb"sv, "423b72682a59140c3910afae516ab0e1"sv}, // auto-generated
        Param{"42193b826e3167f335308591a7fb5856"sv, "cd079702b2ce8baad4298d43e395c35e"sv}, // auto-generated
        Param{"6f4490437cd81c02844d98365efe1429"sv, "024fdb3c6bb798a6448b11230c9a278a"sv}, // auto-generated
        Param{"0c9d8e9eaa91b4c064cfd2f21ea04204"sv, "f74788660143a60ef8bab31faaf9c16d"sv}, // auto-generated
        Param{"8e69922c4c4bde494f0bbd7468a44cd9"sv, "74e3972487644d641185783d78d1292c"sv}, // auto-generated
        Param{"5d7d76c7674be6c9db7d62c2190bebe5"sv, "fcde996db7c55d27df8ffff1b42e795f"sv}, // auto-generated
        Param{"cec48e9bdf5c34a9191360e92c0c83f7"sv, "1a01ec48d42df246f51e6d9de48c3c76"sv}, // auto-generated
        Param{"594773ee44eda635428a815d9e405134"sv, "176a2bfe8e08a28a4a3767d517b95f17"sv}, // auto-generated
        Param{"ef90f7e86530c404896637ee10b4d963"sv, "748309cbc1ba602e1b724d9914bdf4d2"sv}, // auto-generated
        Param{"721ef9d436c9f4e2ffa685d30887d382"sv, "1f403b46ea07b0dbc743e8b638d7ae7a"sv}, // auto-generated
        Param{"20de123931502337333c828116ad7037"sv, "75aad9ec2c95b53997d646ab869ccfdf"sv}, // auto-generated
        Param{"205d58c5e3ee05c577c748d630c37583"sv, "45fccc6f38814631b9708f93d32de3f9"sv}, // auto-generated
        Param{"822a2102e49ceab5b9f7fae419d4b0a2"sv, "86e19abf91d623583b04e16ad7264853"sv}, // auto-generated
        Param{"f44cff04802c92d6217621588768f313"sv, "c3e68ce526080757b6a5eb1d2c1cc77a"sv}, // auto-generated
        Param{"a4663ae6fa3f7fa80a3581d19152396b"sv, "b684ea7167b2b9c8fe04d8607fe0980f"sv}, // auto-generated
        Param{"7a594b51ac6a8fd0a8b1de03e39a86ac"sv, "e9575a90977cafe732502ad695dc1a2c"sv}, // auto-generated
        Param{"7268b34e5d28cd4c05e5d10d2dcb0ee3"sv, "ed3fe142f705cb8be1b85be160a00cc0"sv}, // auto-generated
        Param{"52594124f4c0e55d9f52ea722fab6047"sv, "6aea8116e02e74b75297cb6a02f453e2"sv}, // auto-generated
        Param{"119b0aabf277a05ac9664afa6553c0f5"sv, "0b84630ace1e6cd7fae374d61fdefee6"sv}, // auto-generated
        Param{"db359ded006393688198d5be53d4b23a"sv, "03726a471782186788b48fe6c43ebaab"sv}, // auto-generated
        Param{"89990ab0b0354516ed8aea88ae799a4c"sv, "32d4d5c864e57d8a04b5bc9a064666fa"sv}, // auto-generated
        Param{"3d4a4c156139e708404de62ae0d2d7be"sv, "b6ad5de66193d63ddface49ac40f1b59"sv}, // auto-generated
        Param{"d791dfd81aa02ef5ce47126d237cee27"sv, "e79b7caf2c130d62472875db9a3288e6"sv}, // auto-generated
        Param{"bacf04c3d7cb149cb3e91686e4a0ec36"sv, "76f39f9fd4ba67f36b94001c840cd19b"sv}, // auto-generated
        Param{"d40c93ad187a226b7342b7506adbdda3"sv, "fde622e33bb34525a12da244967e0ebe"sv}, // auto-generated
        Param{"f7fa803a0587fa1e5c7a097209fd2f22"sv, "b8e8cba3203d102a97c1497f23c20042"sv}, // auto-generated
        Param{"8cc9b7fc7538e59be9b73871b10336a3"sv, "b8ec58a27d1d0b3554aea1681be5c821"sv}, // auto-generated
        Param{"dfd698b0d16205b5a40e1de07e74748c"sv, "58a74fdd023507d604724f6b39b9ba48"sv}, // auto-generated
        Param{"0ac6703f3ce95b35e8c8138d8bad26ca"sv, "c795f10345f17f5a4491bcdfe559bc9a"sv}, // auto-generated
        Param{"e71bd7dcdc60efe36d50da687206964e"sv, "12064f695528f7315fa67df624d8354c"sv}, // auto-generated
        Param{"a3cbeb7425ec5790aa9607012bbc2232"sv, "91704ac8c3459804ab718e8b54d527c9"sv}, // auto-generated
        Param{"869fbe3eda20c63d4998fcd3d43b0cfb"sv, "da2b179c2f66a9ddc487391666a3fb7d"sv}, // auto-generated
        Param{"140f9f4d84344dcd44f42505307e1cab"sv, "54148876c2fd0d9a8e4f66c34661c6ab"sv}, // auto-generated
        Param{"5b855a28b83ad4ba1eca032a884f3adf"sv, "42c9cbb3a6eba9d6388a58e1c063d073"sv}, // auto-generated
        Param{"817588d2072fca1e90abc2e6b91671dd"sv, "8a8d3254e7314c1bdbcb81bd8df046c3"sv}, // auto-generated
        Param{"e7666d8bb59062923dabf9d2ee07322b"sv, "d8f82aefba09ec9fe5e2c968cc0e9ad7"sv}, // auto-generated
        Param{"6010f21756177523c337389e619b9004"sv, "d33dfe54e6b4e14325638aa8b9aa7d5e"sv}, // auto-generated
        Param{"4569fbfbc9097d552a86ff15d5c56477"sv, "259ed246a677b5a3b9fac584449385ee"sv}, // auto-generated
        Param{"2e229f8d57f01b382f7e15b432cec90d"sv, "de9aec9f6db9dfec36c8ae135efb9f11"sv}, // auto-generated
        Param{"7301f648ef87dc6419750d94fc8f98e1"sv, "8af64bbb4cd221ed35a80347309d4997"sv}, // auto-generated
        Param{"32d2983345e23d08a44efbedf305aa64"sv, "0f66dc839f9cdaf8098cac103c03b741"sv}, // auto-generated
        Param{"a699b389c094f765c0f8c1189641b5d0"sv, "5c6a34877d464ef28502173959a54b7d"sv}, // auto-generated
        Param{"9be723d0e998cefefcdc4d3b42b79eec"sv, "1f1e5bd5aff35d5b4495636d83dcddd8"sv}, // auto-generated
        Param{"8dda0c99c3a5e402dd55d931f45aa936"sv, "14df54784108cf7b7f9bf0ea8c830a7a"sv}, // auto-generated
        Param{"075559faa14302e428b235cdd47696e4"sv, "d28b2d12b8adb4e7cf9dda0b953ec577"sv}, // auto-generated
        Param{"6ffb196c08896b0a759eaee8865c0e08"sv, "218b7360fd06f34ee1533273c15d8265"sv}, // auto-generated
        Param{"e0da82075e4050bf603f53a5937e15ea"sv, "e70e56006eb2c97a4e3519aeb5260416"sv}, // auto-generated
        Param{"ca31b413d194ac2c2282c5396dcaad8b"sv, "83761de0ebf6a030554b9ce34f359131"sv}, // auto-generated
        Param{"d0a7a797141b31dc7b0cde7f481970ea"sv, "0304b8a4c2b23adc286778e93f95c548"sv}, // auto-generated
        Param{"68b71643593dd572f63c00d90c36533b"sv, "23d6eba4994bed81cc874dcb3c9941bd"sv}, // auto-generated
        Param{"f7da2bfdb227e566f703fdbec4682503"sv, "28df4164f8e3bacd7f89ad043c6aaab9"sv}, // auto-generated
        Param{"c895d9220e3315a4b5f24a5b06c78221"sv, "4ff1e7aeb340358a820c399aff15ae02"sv}, // auto-generated
        Param{"5f6ad89b0d3325cbe9a9907500e7d01f"sv, "cfc5d314d7b56e9401b7483e9cf54bac"sv}, // auto-generated
        Param{"0e7fe9ebfd5e59d12c607ae0b02f6f6f"sv, "50663f3eb1d69bc5d6711ac71b4a9bc2"sv}, // auto-generated
        Param{"3c5a7ebe4210e78e896da168148d98d6"sv, "0ac6bc604b1240d821948f4fe81468c4"sv}, // auto-generated
        Param{"87f7eb71ece3e31420cfd9a57504dff5"sv, "88f431b12a2ee038f34f083ac607bfe8"sv}, // auto-generated
        Param{"2b4b1c93614bfa9098a1adf54f721e2f"sv, "5ec3ff0be61c89eb00e973507975a244"sv}, // auto-generated
        Param{"14278182c42cf331f041d5c971c07235"sv, "64149f3c2c1242224384e140be0690ad"sv}, // auto-generated
        Param{"9122d20ed31f49c3fffc42d40db44b67"sv, "f349cbeaebc170a14dfaa2031d984c00"sv}, // auto-generated
        Param{"492ebbc1d899ef6722cf418b1c5374bd"sv, "26d5c607d984446f48fac385b50c89b3"sv}, // auto-generated
        Param{"65a2b62eccc76894af1a0df81c242e02"sv, "49ae10617d8410c576fbe77190b73159"sv}, // auto-generated
        Param{"41f60edd67565c9b2cc00741b4c6c69b"sv, "3b570d16b32e48b6c53d950083e61f71"sv}, // auto-generated
        Param{"83043cd980f833ae44acd952e9232d64"sv, "ce77c1a66ee42be44c41418cef09e531"sv}, // auto-generated
        Param{"eef218a3af3ab09d96527a11b9ca535a"sv, "cfd32d80e05e7c4f2d40c12855fe4675"sv}, // auto-generated
        Param{"09071fbf1d1268b40606f6905c1466cc"sv, "b8fd300c31c6e50dd6430a85ded70013"sv}, // auto-generated
        Param{"98c2121084336b2527bd20ad772dfac9"sv, "abe733d3685b41f3abb3aecf53f635b2"sv}, // auto-generated
        Param{"7d28fe501961c01682778673f51026ef"sv, "d7d74c49628112692f9b86c22a01d367"sv}, // auto-generated
        Param{"347df4479a66a584330621793b82f8bf"sv, "2bf2f7400cc7171071a943a6ad109455"sv}, // auto-generated
        Param{"50c7b6d70e5c118b556fde65db65e74b"sv, "667a172d5a9783cb9a75b31320b4d5fd"sv}, // auto-generated
        Param{"4e3d4e20b2c5f8ca9ef0b882349bcfcc"sv, "463ac7ce05e90b6c428c2b6033e55c77"sv}, // auto-generated
        Param{"552a63290ab97eb08b58f514bb949883"sv, "836908a78e27f8887bc4cd0e87e110b7"sv}, // auto-generated
        Param{"bf950172f54eb7a4ae4d15cf1a59fc7f"sv, "e191fa61bd64700b79ce69537b1e1f8a"sv}, // auto-generated
        Param{"89689537a9458c2c22cfe6335892decb"sv, "e9ccf1e7cb862bd356273f6dcc06afcd"sv}, // auto-generated
        Param{"e9834e7df19a6df34806536e74daf7cb"sv, "c64feadc1988eb872c98e2e9b81763b4"sv}, // auto-generated
        Param{"47068601f4fdcc0ef6e425418bfd9a53"sv, "901e9cc97fea799327d996127b04699e"sv}, // auto-generated
        Param{"c01fb2e020cb47166cd7a90051e93826"sv, "32bddbb97f4dfbe0d75aa8cb15ef2b48"sv}, // auto-generated
        Param{"39ce99cc228137afa9fa3c9025953b3c"sv, "930f642ca7060ee6e9eefc505dc6cb67"sv}, // auto-generated
        Param{"c739894b4a0b21db7d35121a14672355"sv, "cb99f180304f23b8798dfb0a36b5bd52"sv}, // auto-generated
        Param{"d3f9d462056319630758be902f8dd50e"sv, "356d76d2bfa988c09c63d6d80c57be5c"sv}, // auto-generated
        Param{"22ebb6c4b50f700f5dbe12f472e71a54"sv, "13168d39fbdf00f1744180d1dc5d53e6"sv}, // auto-generated
        Param{"03f0cfc4a68a3a3face5eb80b9751d70"sv, "d3060e981131770b7725b48eb80729b7"sv}, // auto-generated
        Param{"90417f5f216af96ad8aa1d42a9f2243a"sv, "9932f6284f290b6265d14dbb55a5da06"sv}, // auto-generated
        Param{"5e6bfe05b440226fa9231dcebf928f02"sv, "894afb4f00c7bfbde1bdc1435305e263"sv}, // auto-generated
        Param{"b87f279cd6f5e0e28c6284e670ca5592"sv, "2dd2b0f584c40bc0e64a465fd50c833c"sv}, // auto-generated
        Param{"720c92dec82736c6c247f59e526ea819"sv, "61f48401d61e5eac13e6fd72acb1ab63"sv}, // auto-generated
        Param{"8a0eae85e69b2751530017f7e479b366"sv, "ba86d4f7b68aba59d0bd2f221749c0b1"sv}, // auto-generated
        Param{"162e6bc3b61ed40b549e60948797c95b"sv, "bf2ecd39b1081842498c740ab0d64e56"sv}, // auto-generated
        Param{"f1f0786da6172553858fca19699a93d4"sv, "ee1801e8f8447286d45a3aa33036020f"sv}, // auto-generated
        Param{"02c24fedf945504a616631e99cc23ac7"sv, "414d818f1028726fba180c09e52dc66a"sv}, // auto-generated
        Param{"71380c425e740ab354be62f8abd5e350"sv, "c4b018072efc000d499c23d1c696311b"sv}, // auto-generated
        Param{"ea9430038be4899622ba5da85ae9952d"sv, "fa377b8eb9f2796918fd990ea7727ce2"sv}, // auto-generated
        Param{"6b72b3bc1ace842eb3e660e306dddadf"sv, "3bacce2522fac368c3f47a0663161bfb"sv}, // auto-generated
        Param{"6951463df4914f24a105455282307597"sv, "59f98293ff36a6b251d777dc18c8e479"sv}, // auto-generated
        Param{"2f9287fc7456471fad2d843834ec4301"sv, "5f92d24c32471ee9a04eb95ed8680633"sv}, // auto-generated
        Param{"8efc6456bad4022eb48dc9ec3038ff48"sv, "ae1e4f220a0c5f32eb26bd047f73428f"sv}, // auto-generated
        Param{"bb0a6e351446127bef61ce3450264137"sv, "11f66b164fe8a2b5938d1aa85f9d09ac"sv}, // auto-generated
        Param{"4d2962ff7dc3498b5976f5160f8df61a"sv, "f759ec08dfcd407695303528a8c4a2de"sv}, // auto-generated
        Param{"58566ccf479fe20e6e0c8f4ba269d474"sv, "75e308b02f7fc944b7c0fa1e3bfe5ee4"sv}, // auto-generated
        Param{"c27fd602d0029ab62c72c54c867139b2"sv, "2d36a4b1ec5e0fbf7a1cf4cb016a048a"sv} // auto-generated
        ));
