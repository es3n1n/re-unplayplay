from re_unplayplay import decrypt_key, bind_key


def test_bind_key() -> None:
    decrypted = decrypt_key(bytes.fromhex('01'))
    assert bind_key(decrypted, '01').hex() == 'e32698dcafaba7529a223c8e34ec08cc'
