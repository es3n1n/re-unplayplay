import _re_unplayplay as _impl


def decrypt_key(encrypted_key: bytes) -> bytes:
    return _impl.decrypt_key(encrypted_key)


def bind_key(decrypted_key: bytes, file_id: str) -> bytes:
    return _impl.bind_key(decrypted_key, file_id)


def decrypt_and_bind_key(encrypted_key: bytes, file_id: str) -> bytes:
    return _impl.decrypt_and_bind_key(encrypted_key, file_id)


def get_token() -> bytes:
    return _impl.get_token()
