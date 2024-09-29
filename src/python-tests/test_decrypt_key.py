from re_unplayplay import decrypt_key


def test_decrypt_key() -> None:
    assert decrypt_key(bytes.fromhex('c3260ffdf68e9b5b9dc494a52343a698')).hex() == '0caff9fde4054226aa40f4bbc67318e3'
