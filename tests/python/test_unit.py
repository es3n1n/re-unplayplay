from re_unplayplay import decrypt_and_bind_key


def test_decrypt_and_bind_key() -> None:
    assert (
        decrypt_and_bind_key(bytes.fromhex('01'), '01').hex().upper()
        == 'E6B81C1574CFE0E1A4D78D042E290D29'
    )
