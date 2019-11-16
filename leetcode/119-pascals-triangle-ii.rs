// 119. Pascal's Triangle II
// https://leetcode.com/problems/pascals-triangle-ii/

struct Solution { }

impl Solution {
    pub fn get_row(num_rows: i32) -> Vec<i32> {
        match num_rows {
            0 => vec![1],
            _ => Solution::generate_row(&Solution::get_row(num_rows - 1)),
        }
    }

    fn generate_row(row: &Vec<i32>) -> Vec<i32> {
        [vec![1], (0..row.len() - 1).map(|n| row[n] + row[n + 1]).collect(), vec![1]].concat()
    }
}

fn main() {
    println!("{:?}", Solution::get_row(0));
    println!("{:?}", Solution::get_row(1));
    println!("{:?}", Solution::get_row(2));
    println!("{:?}", Solution::get_row(3));
    println!("{:?}", Solution::get_row(4));
    println!("{:?}", Solution::get_row(33));
}
