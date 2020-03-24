// 202. Happy Number
// https://leetcode.com/problems/happy-number/

use std::collections::HashSet;

struct Solution { }

impl Solution {
    pub fn is_happy(n: i32) -> bool {
        let mut m = n;
        let mut set = HashSet::new();
        loop {
            set.insert(m);
            if m == 1 { return true; }
            m = Solution::digits(m).iter().map(|i| i * i).sum();
            if set.contains(&m) { return false; }
        }
    }

    pub fn digits(mut n: i32) -> Vec<i32> {
        let mut v = Vec::new();
        loop {
            v.push(n % 10);
            n /= 10;
            if n == 0 { return v; }
        }
    }
}

fn main() {
    println!("{:?}", Solution::is_happy(19));
    println!("{:?}", Solution::is_happy(10));
    println!("{:?}", Solution::is_happy(61));
    println!("{:?}", Solution::is_happy(1122334387));
}
