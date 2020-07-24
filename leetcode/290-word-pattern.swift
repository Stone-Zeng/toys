// 290. Word Pattern
// https://leetcode.com/problems/word-pattern/

class Solution {
    func wordPattern(_ pattern: String, _ str: String) -> Bool {
        let strList = str.split(separator: " ")
        if pattern.count != strList.count { return false }
        var dict = [Character: String]()
        for c in zip(pattern, strList) {
            let s = String(c.1)
            if let old = dict.updateValue(s, forKey: c.0) {
                if old != s { return false }
            }
        }
        if dict.values.count != Set(dict.values).count { return false }
        return true
    }
}

print(Solution().wordPattern("abba", "dog cat cat dog"))
print(Solution().wordPattern("abba", "dog cat cat fish"))
print(Solution().wordPattern("aaaa", "dog cat cat dog"))
print(Solution().wordPattern("abba", "dog dog dog dog"))
