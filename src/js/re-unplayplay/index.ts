const _re_unplayplay = require("pkg-prebuilds")(
    __dirname + '../../../../',
    require("../../../binding-options.js")
);

export function decryptKey(encryptedKey: Buffer): Buffer {
    return _re_unplayplay.decryptKey(encryptedKey);
}

export function bindKey(decryptedKey: Buffer, fileId: string): Buffer {
    return _re_unplayplay.bindKey(decryptedKey, fileId);
}

export function decryptAndBindKey(encryptedKey: Buffer, fileId: string): Buffer {
    return _re_unplayplay.decryptAndBindKey(encryptedKey, fileId);
}

export function getToken(): Buffer {
    return _re_unplayplay.getToken();
}
