from re_unplayplay import decrypt_key


def test_decrypt_key() -> None:
    assert decrypt_key(bytes.fromhex('01')).hex() == '5d528f92bfb6a6b9dadf75e9f2bdff20'
