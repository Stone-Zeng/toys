// 278. First Bad Version
// https://leetcode.com/problems/first-bad-version/

/**
 * The knows API is defined in the parent class VersionControl.
 *     func isBadVersion(_ version: Int) -> Bool{}
 */
class VersionControl {
    func isBadVersion(_ version: Int) -> Bool {
        version >= 4
    }
}

class Solution : VersionControl {
    func firstBadVersion(_ n: Int) -> Int {
        if isBadVersion(1) { return 1 }
        var (left, right) = (1, n)
        while right - left > 1 {
            let half = (left + right) / 2
            if isBadVersion(half) { right = half } else { left = half }
        }
        return right
    }
}

print(Solution().firstBadVersion(4))
print(Solution().firstBadVersion(5))
print(Solution().firstBadVersion(6))
