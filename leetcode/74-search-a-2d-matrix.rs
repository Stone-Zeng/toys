// 74. Search a 2D Matrix
// https://leetcode.com/problems/search-a-2d-matrix/

struct Solution { }

impl Solution {
    pub fn search_matrix(matrix: Vec<Vec<i32>>, target: i32) -> bool {
        if matrix.len() == 0 || matrix[0].len() == 0 { return false; }

        let m = matrix.len();
        let n = matrix[0].len();

        if matrix[0][0] > target || matrix[m - 1][n - 1] < target { return false; }

        let mut i0 = 0;
        let mut i1 = m;
        while i1 - i0 > 1 {
            let i = (i0 + i1) / 2;
            if matrix[i][0] == target { return true; }
            if matrix[i][0] > target { i1 = i; }
            else { i0 = i; }
        }

        if matrix[i0][0] == target || matrix[i0][n - 1] == target { return true; }

        let mut j0 = 0;
        let mut j1 = n;
        while j1 - j0 > 1 {
            let j = (j0 + j1) / 2;
            if matrix[i0][j] == target { return true; }
            if matrix[i0][j] > target { j1 = j; }
            else { j0 = j; }
        }

        false
    }
}

fn main() {
    println!("{:?}", Solution::search_matrix(vec![], 3));
    println!("{:?}", Solution::search_matrix(vec![vec![], vec![]], 3));
    println!("{:?}", Solution::search_matrix(vec![vec![1]], 1));
    println!("{:?}", Solution::search_matrix(vec![vec![1,2]], 1));
    println!("{:?}", Solution::search_matrix(vec![vec![1], vec![2]], 1));
    println!("{:?}", Solution::search_matrix(vec![vec![1], vec![2]], 2));
    println!("{:?}", Solution::search_matrix(vec![vec![1,3,5,7],vec![10,11,16,20],vec![23,30,34,50]], 3));
    println!("{:?}", Solution::search_matrix(vec![vec![1,3,5,7],vec![10,11,16,20],vec![23,30,34,50]], 13));
    println!("{:?}", Solution::search_matrix(vec![vec![1,3,5,7,8],vec![10,11,16,20,21],vec![23,30,34,50,51]], 51));
    println!("{:?}", Solution::search_matrix(vec![vec![1,3,5,7,8],vec![10,11,16,20,21],vec![23,30,34,50,51]], 43));
}
