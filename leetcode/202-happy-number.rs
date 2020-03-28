// 202. Happy Number
// https://leetcode.com/problems/happy-number/

struct Solution { }

impl Solution {
    pub fn is_happy(n: i32) -> bool {
        let mut m = n;
        let mut set = std::collections::HashSet::new();
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
    for i in &[19, 10, 61, 1122334387] {
        println!("{:?}", Solution::is_happy(*i));
    }
}
