// 367. Valid Perfect Square
// https://leetcode.com/problems/valid-perfect-square/

struct Solution { }

impl Solution {
    pub fn is_perfect_square(num: i32) -> bool {
        for i in 0..46341 {
            if i * i == num { return true }
            else if i * i > num { return false }
        }
        false
    }
}

fn main() {
    for i in vec![1, 14, 16, 65536, 2147483647] {
        println!("{:?} -> {:?}", i, Solution::is_perfect_square(i));
    }
}
