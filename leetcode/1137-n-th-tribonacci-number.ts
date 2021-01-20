// 1137. N-th Tribonacci Number
// https://leetcode.com/problems/n-th-tribonacci-number/

let tribonacciData: number[] = [0, 1, 1];

function tribonacci(n: number): number {
    if (n < tribonacciData.length) return tribonacciData[n];
    const t = tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
    tribonacciData.push(t);
    return t;
};

[...Array(37)].forEach((_, i) => console.log(i, tribonacci(i)));
