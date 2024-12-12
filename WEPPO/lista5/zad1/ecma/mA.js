import { work_b } from './mB.js';

export function work_a(n) {
    if (n > 0) {
        console.log(`a: ${n}`);
        work_b(n - 1);
    }
}
