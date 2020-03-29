// 73. Set Matrix Zeroes
// https://leetcode.com/problems/set-matrix-zeroes/

struct Solution { }

impl Solution {
    pub fn set_zeroes(matrix: &mut Vec<Vec<i32>>) {
        let m = matrix.len();
        if m == 0 { return; }
        let n = matrix[0].len();
        if n == 0 { return; }

        let mut row_nums = std::collections::HashSet::new();
        let mut col_nums = std::collections::HashSet::new();

        for i in 0..m {
            for j in 0..n {
                if matrix[i][j] == 0 {
                    row_nums.insert(i);
                    col_nums.insert(j);
                }
            }
        }

        let zero_row = vec![0; n];
        for i in &row_nums {
            matrix[*i] = zero_row.clone();
        }

        for i in 0..m {
            for j in &col_nums {
                matrix[i][*j] = 0;
            }
        }
    }
}

fn main() {
    for i in &mut [
        vec![vec![1,1,1], vec![1,0,1], vec![1,1,1]],
        vec![vec![0,1,2,0], vec![3,4,5,2], vec![1,3,1,5]],
    ] {
        Solution::set_zeroes(i);
    }
}
