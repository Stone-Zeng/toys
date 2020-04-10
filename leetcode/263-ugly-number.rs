// 263. Ugly Number
// https://leetcode.com/problems/ugly-number/

struct Solution { }

impl Solution {
    pub fn is_ugly(num: i32) -> bool {
        if num > 0 {
            let mut num = num;
            for i in &[2, 3, 5] {
                while num % i == 0 { num /= i; }
            }
            num == 1
        } else {
            false
        }
    }
}

fn main() {
    for i in vec![1,2,4,14,-948687736,513187238,1720833206,-1185011834,-1625281697] {
        println!("{}", Solution::is_ugly(i));
    }
}
