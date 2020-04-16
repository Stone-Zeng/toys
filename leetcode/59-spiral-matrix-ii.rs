// 59. Spiral Matrix II
// https://leetcode.com/problems/spiral-matrix-ii/

struct Solution { }

impl Solution {
    pub fn generate_matrix(n: i32) -> Vec<Vec<i32>> {
        let mut result = vec![vec![0; n as usize]; n as usize];
        let mut i_min = 0;
        let mut j_min = 0;
        let mut i_max = (n - 1) as usize;
        let mut j_max = (n - 1) as usize;
        let mut e = 1;
        loop {
            for j in j_min..=j_max {
                result[i_min][j] = e;
                e += 1;
            }
            i_min += 1;
            if i_min > i_max {
                return result;
            }

            for i in i_min..=i_max {
                result[i][j_max] = e;
                e += 1;
            }
            j_max -= 1;
            if j_max < j_min {
                return result;
            }

            for j in (j_min..=j_max).rev() {
                result[i_max][j] = e;
                e += 1;
            }
            i_max -= 1;
            if i_max < i_min {
                return result;
            }

            for i in (i_min..=i_max).rev() {
                result[i][j_min] = e;
                e += 1;
            }
            j_min += 1;
            if j_min > j_max {
                return result;
            }
        }
    }
}

fn main() {
    for i in &[1,2,3,4,5,6] {
        println!("{:?}", Solution::generate_matrix(*i));
    }
}
