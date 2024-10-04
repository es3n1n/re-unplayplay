"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
const binding_1 = require("binding");
describe('binding', () => {
    test('hello function returns expected string', () => {
        const result = (0, binding_1.hello)();
        expect(result).toBe('world'); // Replace 'world' with the expected return value
    });
});
