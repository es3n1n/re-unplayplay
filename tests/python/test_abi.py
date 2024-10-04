from re_unplayplay import decrypt_key, bind_key, decrypt_and_bind_key, get_token


def test_decrypt_key_func() -> None:
    assert isinstance(decrypt_key(bytes.fromhex('01')), bytes)


def test_bind_key_func() -> None:
    assert isinstance(bind_key(bytes.fromhex('01'), '01'), bytes)


def test_decrypt_and_bind_key_func() -> None:
    assert isinstance(decrypt_and_bind_key(bytes.fromhex('01'), '01'), bytes)


def test_get_token_func() -> None:
    assert isinstance(get_token(), bytes)
