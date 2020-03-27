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
    println!("{}", Solution::is_power_of_two(0));
    println!("{}", Solution::is_power_of_two(-1));
    println!("{}", Solution::is_power_of_two(1));
    println!("{}", Solution::is_power_of_two(16));
    println!("{}", Solution::is_power_of_two(218));
    println!("{}", Solution::is_power_of_two(1073741824));
    println!("{}", Solution::is_power_of_two(2147483647));
}
