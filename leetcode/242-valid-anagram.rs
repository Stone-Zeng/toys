// 242. Valid Anagram
// https://leetcode.com/problems/valid-anagram/

struct Solution { }

impl Solution {
    pub fn is_anagram(s: String, t: String) -> bool {
        let mut map_s = std::collections::HashMap::new();
        let mut map_t = std::collections::HashMap::new();
        for i in s.chars() {
            *map_s.entry(i).or_insert(0) += 1;
        }
        for j in t.chars() {
            *map_t.entry(j).or_insert(0) += 1;
        }
        map_s == map_t
    }
}

fn main() {
    for i in &[
        ("", ""),
        ("aa", "aa"),
        ("anagram", "nagaram"),
        ("rat", "car"),
        (
            "印地语（天城文：हिन्दी或हिंदी，拉丁字母转写：Hindī）又称印度语、印度文，是印欧语系印度-伊朗语族中印度-雅利安语支下的一种语言",
            "城写ी，n拉度्或伊言）字-种又文印地系转利ं-i、H丁度雅印中度印语称ह，द下印语द安度印天ह语ि支一是母文ī的（ीि语族欧न印：语朗：语d"
        ),
    ] {
        println!("{}", Solution::is_anagram((*i.0).to_string(), (*i.1).to_string()));
    }
}
