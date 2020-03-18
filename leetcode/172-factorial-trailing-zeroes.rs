// 172. Factorial Trailing Zeroes
// https://leetcode.com/problems/factorial-trailing-zeroes/

struct Solution { }

impl Solution {
    pub fn trailing_zeroes(n: i32) -> i32 {
        if n < 5 {
            0
        } else {
            let k = (n as f32).log(5.0) as i32;
            let base: i32 = 5;
            (1..=k).map(|i| n / base.pow(i as u32)).sum()
        }
    }
}

fn main() {
    println!("{}", Solution::trailing_zeroes(0));
    println!("{}", Solution::trailing_zeroes(3));
    println!("{}", Solution::trailing_zeroes(5));
    println!("{}", Solution::trailing_zeroes(27));
    println!("{}", Solution::trailing_zeroes(270));
    println!("{}", Solution::trailing_zeroes(1000));
    println!("{}", Solution::trailing_zeroes(1808548329));
}
