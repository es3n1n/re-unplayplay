from re_unplayplay import decrypt_and_bind_key


def test_decrypt_and_bind_key() -> None:
    assert (
        decrypt_and_bind_key(bytes.fromhex('01'), '01').hex().upper()
        == '7EE4480B767DD92A03E90A7FC1FF4099'
    )
