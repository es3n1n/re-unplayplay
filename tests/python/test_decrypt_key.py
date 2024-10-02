from re_unplayplay import decrypt_key


def test_decrypt_key() -> None:
    assert decrypt_key(bytes.fromhex('52f5a2b7ab3130efc7a9fc76e873d4b5')).hex() == '241608b73ff02eb0f38c9fe0f5ad1428'
