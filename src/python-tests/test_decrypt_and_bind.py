from re_unplayplay import decrypt_and_bind_key


def test_bind_key() -> None:
    assert (
        decrypt_and_bind_key(bytes.fromhex('01'), '01').hex()
        == 'f3a37e28d15bc5e8151d413eb36a59b5'
    )
