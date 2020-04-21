// 268. Missing Number
// https://leetcode.com/problems/missing-number/

struct Solution { }
impl Solution {
    pub fn missing_number(nums: Vec<i32>) -> i32 {
        let n = nums.len() as i32;
        let sum: i32 = nums.iter().sum();
        n * (n + 1) / 2 - sum
    }
}

fn main() {
    println!("{}", Solution::missing_number(vec![3,0,1]));
    println!("{}", Solution::missing_number(vec![9,6,4,2,3,5,7,0,1]));
}
