"""1. Two Sum
https://leetcode.com/problems/two-sum
"""


class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        N = len(nums)
        for i in range(N):
            x = nums[i]
            for j in range(i + 1, N):
                if x + nums[j] == target:
                    return [i, j]


def _test():
    sol = Solution()
    print(sol.twoSum([1, 2, 4, 5, 78, 14, 26, 13], 27))
    print(sol.twoSum([1, 2, 4, 5, 78, 14, 26, 13], 39))

if __name__ == "__main__":
    _test()
