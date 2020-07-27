// 344. Reverse String
// https://leetcode.com/problems/reverse-string/

class Solution {
    func reverseString(_ s: inout [Character]) {
        if s.count >= 2 {
            for i in 0...(s.count / 2 - 1) {
                let lastIndex = s.count - 1 - i
                let temp = s[i]
                s[i] = s[lastIndex]
                s[lastIndex] = temp
            }
        }
    }
}

for var s: [Character] in [
    [],
    ["a"],
    ["a","-"],
    ["h","e","l","l","o"],
    ["H","a","n","n","a","h"],
] {
    Solution().reverseString(&s)
    print(s)
}
