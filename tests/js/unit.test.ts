import { decryptAndBindKey } from '../../src/js/re-unplayplay';


describe('binding', () => {
    test('unit', () => {
        const result = decryptAndBindKey(Buffer.from('01', 'hex'), "01");
        expect(result.toString('hex').toUpperCase()).toBe('523FF1673A7A66E4BA8435B18F69D6D6');
    });
});
