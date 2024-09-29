from re_unplayplay import decrypt_and_bind_key


def test_bind_key() -> None:
    assert (
        decrypt_and_bind_key(bytes.fromhex('01'), '01').hex()
        == 'e32698dcafaba7529a223c8e34ec08cc'
    )
