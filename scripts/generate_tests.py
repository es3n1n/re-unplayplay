from re_unplayplay import decrypt_key
from os import urandom
from sys import argv

N = 150


def generate_key_decrypt_tests():
    for i in range(N):
        arg = urandom(16)
        l = 'Param{"' + arg.hex() + '"sv, "' + decrypt_key(arg).hex() + '"sv}'
        if i < (N - 1):
            l += ','
        l += ' // auto-generated'
        print(l, flush=True)


def main() -> None:
    if 'decrypt' in argv:
        generate_key_decrypt_tests()


if __name__ == '__main__':
    main()
