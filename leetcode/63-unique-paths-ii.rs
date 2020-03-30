// 63. Unique Paths II
// https://leetcode.com/problems/unique-paths-ii/

struct Solution { }

impl Solution {
    pub fn unique_paths_with_obstacles(obstacle_grid: Vec<Vec<i32>>) -> i32 {
        let m = obstacle_grid.len();
        let n = obstacle_grid[0].len();

        let mut i1 = m;
        let mut j1 = n;

        let mut result_grid = vec![vec![0; n]; m];

        for i in 0..m {
            if obstacle_grid[i][0] == 1 {
                i1 = i;
                break;
            }
        }
        for i in 0..i1 {
            result_grid[i][0] = 1;
        }

        for j in 0..n {
            if obstacle_grid[0][j] == 1 {
                j1 = j;
                break;
            }
        }
        for j in 0..j1 {
            result_grid[0][j] = 1;
        }

        for i in 1..m {
            for j in 1..n {
                if obstacle_grid[i][j] == 1 {
                    result_grid[i][j] = 0;
                } else {
                    result_grid[i][j] = result_grid[i][j - 1] + result_grid[i - 1][j];
                }
            }
        }
        result_grid[m - 1][n - 1]
    }
}

fn main() {
    for i in &[
        vec![vec![0]],
        vec![vec![0,0]],
        vec![vec![1,0]],
        vec![vec![0,1,0], vec![0,1,0]],
        vec![vec![0,0,0], vec![0,1,0], vec![0,0,0]],
        vec![vec![0,0,1,0], vec![1,0,0,0], vec![0,1,0,0], vec![0,0,0,0], vec![0,1,0,0]],
        vec![vec![0,0,0,0,0,0],vec![0,0,0,0,0,0],vec![0,0,0,0,0,1],vec![1,0,0,0,0,0]],
    ] {
        println!("{}", Solution::unique_paths_with_obstacles(i.to_vec()));
    }
}
