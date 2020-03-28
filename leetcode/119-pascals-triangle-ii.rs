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
    for i in &[0, 1, 2, 3, 4, 33] {
        println!("{:?}", Solution::get_row(*i));
    }
}
