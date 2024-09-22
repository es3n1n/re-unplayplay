# re-unplayplay

A rewritten version of [unplayplay](https://git.gay/uhwot/unplayplay), which is a slightly edited version of [pbdecrypt.cc](https://github.com/baltitenger/spsync/blob/master/ppdecrypt.cc).

___
## Usage

### C++

```cpp
#include <unplayplay.hpp>

int main(const int argc, const char* argv[]) {
    if (argc < 2) {
        std::cerr << "usage: " 
                  << argv[0] 
                  << " {file_id} {obfuscated_key}" 
                  << std::endl;
        return 1;
    }

    const auto file_id = unplayplay::util::FileId(
        argv[1]
    );
    const auto obfuscated_key = unplayplay::util::Key(
        argv[2]
    );
    
    const auto decrypted_key = unplayplay::decrypt_key(
        obfuscated_key
    );
    const auto result = unplayplay::bind_key(
        decrypted_key, file_id
    );

    for (std::size_t i = 0; i < result.size(); ++i) {
        std::cout << std::setw(2) 
                  << std::setfill('0') 
                  << std::hex 
                  << static_cast<int>(result[i]);
    }
    std::cout << std::endl;

    return 0;
}
```

### Python

Coming soon

### NodeJS

Coming soon

## Installing/building

### C++ (cli)

```commandline
cmake -B build -DRE_UNPP_BUILD_TESTS=0
cmake --build build --config Release
```

### Python

Coming soon

### NodeJS

Coming soon

## Contributing

Any contributions you make are **greatly appreciated**.

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

___

## License

MIT
