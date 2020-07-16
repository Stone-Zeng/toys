// 31. Next Permutation
// https://leetcode.com/problems/next-permutation/

struct Solution { }

impl Solution {
    fn swap(nums: &mut Vec<i32>, i: usize, j: usize) {
        let temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    fn reverse(nums: &mut Vec<i32>, begin: usize, end: usize) {
        let mut i = 0;
        while 2 * i < end - begin {
            Self::swap(nums, begin + i, end - i);
            i += 1;
        }
    }

    pub fn next_permutation(nums: &mut Vec<i32>) {
        // See https://en.wikipedia.org/wiki/Permutation#Generation_in_lexicographic_order
        let len = nums.len();
        if len > 1 {
            let mut k = -1;
            (0..len - 1).for_each(|i| if nums[i] < nums[i + 1] { k = i as i32; });
            if k == -1 {
                Self::reverse(nums, 0, len - 1);
            } else {
                let k = k as usize;
                let mut l = k;
                (k..len).for_each(|i| if nums[k] < nums[i] { l = i; });
                Self::swap(nums, k, l);
                Self::reverse(nums, k + 1, len - 1);
            }
        }
    }
}

fn main() {
    for v in vec![
        vec![],
        vec![1],
        vec![1,2,3],
        vec![3,2,1],
        vec![1,4,9,7,5,2],
    ] {
        let mut v_perm = v.clone();
        Solution::next_permutation(&mut v_perm);
        println!("{:?} -> {:?}", v, v_perm);
    }
}
