// 217. Contains Duplicate
// https://leetcode.com/problems/contains-duplicate/

struct Solution { }

impl Solution {
    pub fn contains_duplicate(nums: Vec<i32>) -> bool {
        let mut set = std::collections::HashSet::new();
        for i in nums {
            if set.contains(&i) {
                return true;
            } else {
                set.insert(i);
            }
        }
        false
    }
}

fn main() {
    for i in &[
        vec![],
        vec![1,2,3,1],
        vec![1,2,3,4],
        vec![1,1,1,3,3,4,3,2,4,2],
    ] {
        println!("{}", Solution::contains_duplicate(i.to_vec()));
    }
}
