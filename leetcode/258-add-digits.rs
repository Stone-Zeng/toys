// 258. Add Digits
// https://leetcode.com/problems/add-digits/

struct Solution { }

impl Solution {
    pub fn add_digits(num: i32) -> i32 {
        if num < 10 {
            num
        } else {
            let mut num = num;
            let mut sum = 0;
            while num >= 10 {
                sum += num % 10;
                num = (num - num % 10) / 10;
            }
            Solution::add_digits(sum + num)
        }
    }
}

fn main() {
    for i in vec![1,38,1232341,31980490] {
        println!("{}", Solution::add_digits(i));
    }
}
