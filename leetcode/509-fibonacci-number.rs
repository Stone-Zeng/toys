// 509. Fibonacci Number
// https://leetcode.com/problems/fibonacci-number/

struct Solution { }

const FIB_DATA: [i32; 31] = [
    0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811, 514229, 832040,
];

impl Solution {
    pub fn fib(n: i32) -> i32 {
        FIB_DATA[n as usize]
    }
}

fn main() {
    for i in vec![0, 1, 10, 30] {
        println!("{:?} -> {:?}", i, Solution::fib(i));
    }
}
