import { work_a } from './mA.js';

export function work_b(n) {
    if (n > 0) {
        console.log(`b: ${n}`);
        work_a(n - 1);
    }
}
