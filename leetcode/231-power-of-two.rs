// 231. Power of Two
// https://leetcode.com/problems/power-of-two/

struct Solution { }

impl Solution {
    pub fn is_power_of_two(n: i32) -> bool {
        if n <= 0 {
            false
        } else {
            let mut m = n;
            while m > 1 {
                if m % 2 != 0 { return false; }
                m /= 2;
            }
            true
        }
    }
}

fn main() {
    for i in &[0, -1, 1, 16, 218, 1073741824, 2147483647] {
        println!("{}", Solution::is_power_of_two(*i));
    }
}
