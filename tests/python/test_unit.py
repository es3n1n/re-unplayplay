from re_unplayplay import decrypt_and_bind_key


def test_decrypt_and_bind_key() -> None:
    assert (
        decrypt_and_bind_key(bytes.fromhex('01'), '01').hex().upper()
        == '523FF1673A7A66E4BA8435B18F69D6D6'
    )
