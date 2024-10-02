from re_unplayplay import decrypt_key, bind_key


def test_bind_key() -> None:
    decrypted = decrypt_key(bytes.fromhex('01'))
    assert bind_key(decrypted, '01').hex().upper() == 'F4266A5580E7033E424CDE777878BAE8'
