from re_unplayplay import decrypt_key, bind_key


def test_bind_key() -> None:
    decrypted = decrypt_key(bytes.fromhex('01'))
    assert bind_key(decrypted, '01').hex() == 'f3a37e28d15bc5e8151d413eb36a59b5'
