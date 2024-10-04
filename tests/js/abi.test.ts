import { decryptKey, bindKey, decryptAndBindKey, getToken } from '../../src/js/re-unplayplay';


describe('binding', () => {
    test('decryptKey', () => {
        expect(decryptKey(Buffer.from('01', 'hex'))).toBeInstanceOf(Buffer);
    });
    test('bindKey', () => {
        expect(bindKey(Buffer.from('01', 'hex'), '01')).toBeInstanceOf(Buffer);
    });
    test('decryptAndBindKey', () => {
        expect(decryptAndBindKey(Buffer.from('01', 'hex'), '01')).toBeInstanceOf(Buffer);
    });
    test('getToken', () => {
        expect(getToken()).toBeInstanceOf(Buffer);
    });
});
