// 342. Power of Four
// https://leetcode.com/problems/power-of-four/

// Max integer is 2^31-1 > 4^15.
let kNumbers = [1,4,16,64,256,1024,4096,16384,65536,262144,1048576,4194304,16777216,67108864,268435456,1073741824]

class Solution {
    func isPowerOfFour(_ num: Int) -> Bool {
        return kNumbers.contains(num)
    }
}

for i in [0, 1, 3, 4] {
    print(Solution().isPowerOfFour(i))
}
