"""3. Longest Substring Without Repeating Characters
https://leetcode.com/problems/longest-substring-without-repeating-characters/
"""

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        sub_str = s
        sub_str_len = 0
        for i in range(len(s)):
            for j in range(i + 1, len(s)):
                sub_str = s[i:j]
                if s[j] in sub_str:
                    break
                sub_str = s[i:]
            sub_str_len = max(sub_str_len, len(sub_str))
        return sub_str_len

s = Solution()
print(s.lengthOfLongestSubstring("abcabcbb"))
print(s.lengthOfLongestSubstring("bbbbb"))
print(s.lengthOfLongestSubstring("abc"))
print(s.lengthOfLongestSubstring("pwwkew"))
print(s.lengthOfLongestSubstring("pwwkewpwwkewpwwkewpwwkewpwwkewpwwkewpwwkewpwwkewpwwkewpwwkewpwwkewpwwkewpwwkewpwwkewpwwkewpwwkew"))
print(s.lengthOfLongestSubstring(""))
print(s.lengthOfLongestSubstring("b"))
print(s.lengthOfLongestSubstring("bb"))
print(s.lengthOfLongestSubstring("ab"))
print(s.lengthOfLongestSubstring("abb"))
print(s.lengthOfLongestSubstring("https://leetcode.com/problems/longest-substring-without-repeating-characters/"))
