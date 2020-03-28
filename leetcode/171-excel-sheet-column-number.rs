// 171. Excel Sheet Column Number
// https://leetcode.com/problems/excel-sheet-column-number/

struct Solution { }

impl Solution {
    pub fn title_to_number(s: String) -> i32 {
        s.char_indices()
         .map(|(i, c)| (c as i32 - 64) * i32::pow(26, (s.len() - i - 1) as u32))
         .sum()
    }
}

fn main() {
    for i in &["", "A", "AB", "ZY"] {
        println!("{}", Solution::title_to_number(i.to_string()));
    }
}
