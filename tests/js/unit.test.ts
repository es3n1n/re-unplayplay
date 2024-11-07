import { decryptAndBindKey } from '../../src/js/re-unplayplay';


describe('binding', () => {
    test('unit', () => {
        const result = decryptAndBindKey(Buffer.from('01', 'hex'), "01");
        expect(result.toString('hex').toUpperCase()).toBe('E6B81C1574CFE0E1A4D78D042E290D29');
    });
});
