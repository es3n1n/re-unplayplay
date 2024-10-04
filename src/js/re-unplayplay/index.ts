let _re_unplayplay: any;

try {
    /// Production:
    /// dist/src/js/re-unplayplay/index.ts
    _re_unplayplay = require("pkg-prebuilds")(
        __dirname + '../../../../../',
        require(__dirname + "../../../../../binding-options.js"),
    );
} catch(err) {
    /// Development:
    /// src/js/re-unplayplay/index.ts
    _re_unplayplay = require("pkg-prebuilds")(
        __dirname + '../../../../',
        require(__dirname + "../../../../binding-options.js"),
    );
}

if (!_re_unplayplay) {
    throw new Error("_re_unplayplay was not initialized successfully");
}

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
