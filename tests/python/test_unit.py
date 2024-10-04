from re_unplayplay import decrypt_and_bind_key


def test_decrypt_and_bind_key() -> None:
    assert (
        decrypt_and_bind_key(bytes.fromhex('01'), '01').hex().upper()
        == 'F4266A5580E7033E424CDE777878BAE8'
    )
