import { decryptAndBindKey } from '../../src/js/re-unplayplay';


describe('binding', () => {
    test('unit', () => {
        const result = decryptAndBindKey(Buffer.from('01', 'hex'), "01");
        expect(result.toString('hex').toUpperCase()).toBe('F4266A5580E7033E424CDE777878BAE8');
    });
});
