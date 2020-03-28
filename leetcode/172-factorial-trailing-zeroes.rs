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
    for i in &[0, 3, 5, 27, 270, 1000, 1808548329] {
        println!("{}", Solution::trailing_zeroes(*i));
    }
}
