// 62. Unique Paths
// https://leetcode.com/problems/unique-paths/

struct Solution { }

impl Solution {
    pub fn unique_paths(m: i32, n: i32) -> i32 {
        let m_ = i32::min(m, n) as usize;
        let n_ = i32::max(m, n) as usize;
        let mut v = vec![1; m_];
        for _ in 0..n_ - 1 {
            for i in 1..m_ {
                v[i] = v[i - 1] + v[i];
            }
        }
        v[m_ - 1]
    }
}

fn main() {
    for i in &[(3,2), (7,3), (1,1), (1,2), (1,199), (1,200), (3,50)] {
        println!("{}", Solution::unique_paths(i.0, i.1));
    }
}
