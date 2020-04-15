// 56. Merge Intervals
// https://leetcode.com/problems/merge-intervals/

struct Solution { }

impl Solution {
    pub fn merge_(merged: Vec<Vec<i32>>, interval: &Vec<i32>) -> Vec<Vec<i32>> {
        let interval_vec = vec![interval.to_vec()];
        if merged.is_empty() || merged[0].is_empty() {
            interval_vec
        } else {
            let len = merged.len();
            let left = interval[0];
            let right = interval[1];
            if right < merged[0][0] {
                [interval_vec, merged].concat()
            } else if left > merged[len - 1][1] {
                [merged, interval_vec].concat()
            } else {
                let mut i = 0;
                let mut left_pos = (0, "");
                let mut right_pos = (0, "");
                if left < merged[0][0] {
                    left_pos = (0, "L");
                } else {
                    while i < len - 1 {
                        if merged[i][0] <= left && left <= merged[i][1] {
                            left_pos = (i, "M");
                            break;
                        } else if merged[i][1] < left && left < merged[i + 1][0] {
                            left_pos = (i + 1, "L");
                            break;
                        } else {
                            i += 1;
                        }
                    }
                }
                while i < len - 1 {
                    if merged[i][0] <= right && right <= merged[i][1] {
                        right_pos = (i, "M");
                        break;
                    } else if merged[i][1] < right && right < merged[i + 1][0] {
                        right_pos = (i, "R");
                        break;
                    } else {
                        i += 1;
                    }
                }
                if left_pos.1 == "" {
                    left_pos = (len - 1, "M");
                }
                if right_pos.1 == "" {
                    right_pos = if merged[len - 1][0] <= right && right <= merged[len - 1][1] {
                        (len - 1, "M")
                    } else {
                        (len - 1, "R")
                    };
                }

                let first = merged.split_at(left_pos.0).0.to_vec();
                let last = merged.split_at(right_pos.0 + 1).1.to_vec();
                let mid = match (left_pos.1, right_pos.1) {
                    ("L", "R") => [left, right],
                    ("L", "M") => [left, merged[right_pos.0][1]],
                    ("M", "R") => [merged[left_pos.0][0], right],
                    ("M", "M") => [merged[left_pos.0][0], merged[right_pos.0][1]],
                    _ => panic!()
                }.to_vec();

                [first, vec![mid], last].concat()
            }
        }
    }

    pub fn merge(intervals: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        intervals.iter().fold(vec![], Solution::merge_)
    }
}
