// 326. Power of Three
// https://leetcode.com/problems/power-of-three/

// Max integer is 2^31-1 = 2147483647 > 3^19.
let kNumbers = [1,3,9,27,81,243,729,2187,6561,19683,59049,177147,531441,1594323,4782969,14348907,43046721,129140163,387420489,1162261467]

class Solution {
    func isPowerOfThree(_ n: Int) -> Bool {
        return kNumbers.contains(n)
    }
}

for i in [0, 1, 3, 4] {
    print(Solution().isPowerOfThree(i))
}
