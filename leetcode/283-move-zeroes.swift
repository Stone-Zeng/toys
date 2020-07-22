// 283. Move Zeroes
// https://leetcode.com/problems/move-zeroes/

class Solution {
    func moveZeroes(_ nums: inout [Int]) {
        var j = 0
        for i in 0..<nums.count {
            if nums[i] != 0 && i >= j {
                nums[j] = nums[i]
                j += 1
            }
        }
        for i in j..<nums.count {
            nums[i] = 0
        }
    }
}

var nums: [Int] = []
Solution().moveZeroes(&nums)
print(nums)

nums = [0,0]
Solution().moveZeroes(&nums)
print(nums)

nums = [1,2,6,2]
Solution().moveZeroes(&nums)
print(nums)

nums = [0,1,0,3,12]
Solution().moveZeroes(&nums)
print(nums)

nums = [0,1,0,3,12,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5]
Solution().moveZeroes(&nums)
print(nums)
