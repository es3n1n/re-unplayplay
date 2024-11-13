import { decryptAndBindKey } from '../../src/js/re-unplayplay';


describe('binding', () => {
    test('unit', () => {
        const result = decryptAndBindKey(Buffer.from('01', 'hex'), "01");
        expect(result.toString('hex').toUpperCase()).toBe('7EE4480B767DD92A03E90A7FC1FF4099');
    });
});
