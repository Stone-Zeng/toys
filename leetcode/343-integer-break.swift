// 343. Integer Break
// https://leetcode.com/problems/integer-break/

class Solution {
    var resDict: [Int: Int] = [1: 1, 2: 1]

    func integerBreak(_ n: Int) -> Int {
        var res = 0
        for i in 1...(n + 1) / 2 {
            if let val = resDict[n - i] {
                res = max(res, i * max(val, n - i))
            } else {
                resDict[n - i] = integerBreak(n - i)
                res = max(res, i * max(resDict[n - i]!, n - i))
            }
        }
        return res
    }
}

for i: Int in [2, 3, 4, 10, 12, 13, 58] {
    print(i, "=>", Solution().integerBreak(i))
}
