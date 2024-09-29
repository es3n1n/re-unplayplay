# re-unplayplay

[![C++](https://github.com/es3n1n/re-unplayplay/actions/workflows/cxx.yml/badge.svg)](https://github.com/es3n1n/re-unplayplay/actions/workflows/cxx.yml)
[![Python](https://github.com/es3n1n/re-unplayplay/actions/workflows/python.yml/badge.svg)](https://github.com/es3n1n/re-unplayplay/actions/workflows/python.yml)
[![license](https://img.shields.io/github/license/es3n1n/re-unplayplay.svg)](https://github.com/es3n1n/re-unplayplay/blob/naster/LICENSE)
[![pypi](https://img.shields.io/pypi/v/re-unplayplay.svg)](https://pypi.python.org/pypi/re-unplayplay)
[![Downloads](https://static.pepy.tech/badge/re-unplayplay/month)](https://pepy.tech/project/re-unplayplay)

A rewritten version of [unplayplay](https://git.gay/uhwot/unplayplay), which is a slightly edited version of [pbdecrypt.cc](https://github.com/baltitenger/spsync/blob/master/ppdecrypt.cc). \
This library is implementing various cryptography algorithms used by the spotify's DRM called playplay, 
you can refer to [votify](https://github.com/glomatico/votify) to see how it should be used.

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

```python
from re_unplayplay import decrypt_key, bind_key, decrypt_and_bind_key, get_token

# Get the associated token
assert get_token().hex() == '01e132cae527bd21620e822f58514932'

# Decrypt the encrypted key
decrypted = decrypt_key(bytes.fromhex('01'))
assert decrypted.hex() == '89ef56c1d52f28e4c01459c32953c42c'

# Bind decrypted key
bind_result = bind_key(decrypted, '01')
assert bind_result.hex() == 'E32698DCAFABA7529A223C8E34EC08CC'

# Decrypt and bind in one call
result = decrypt_and_bind_key(bytes.fromhex('01'), '01')
assert bind_result.hex() == 'E32698DCAFABA7529A223C8E34EC08CC'
```

### NodeJS

Coming soon

## Installing/building

### C++ (cli)

```commandline
cmake -B build -DRE_UNPP_BUILD_TESTS=0
cmake --build build --config Release
```

### Python

```commandline
python3 -m pip install -U re-unplayplay
```

### NodeJS

Coming soon

___
## Contributing

Any contributions you make are **greatly appreciated**.

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

## License

MIT
