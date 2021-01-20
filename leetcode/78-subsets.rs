// 78. Subsets
// https://leetcode.com/problems/subsets/

struct Solution {}

impl Solution {
    pub fn subsets(nums: Vec<i32>) -> Vec<Vec<i32>> {
        (0..(1 << nums.len()))
            .map(|mut i| {
                let mut pos: usize = 0;
                let mut v = Vec::new();
                while i > 0 {
                    if i % 2 == 1 {
                        v.push(nums[pos]);
                    }
                    i = i >> 1;
                    pos += 1;
                }
                v
            })
            .collect()
    }
}

fn main() {
    for nums in vec![vec![], vec![2, 4, 5]] {
        println!("{:?}", Solution::subsets(nums));
    }
}
