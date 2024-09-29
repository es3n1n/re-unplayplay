from re_unplayplay import decrypt_key, bind_key


def test_bind_key() -> None:
    decrypted = decrypt_key(bytes.fromhex('01'))
    assert bind_key(decrypted, '01').hex() == 'E32698DCAFABA7529A223C8E34EC08CC'
