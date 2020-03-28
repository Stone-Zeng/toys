// 205. Isomorphic Strings
// https://leetcode.com/problems/isomorphic-strings/

struct Solution { }

impl Solution {
    fn _is_isomorphic(s: &String, t: &String) -> bool {
        let mut map = std::collections::HashMap::new();
        for i in 0..s.len() {
            let s_i = s.chars().nth(i).unwrap();
            let t_i = t.chars().nth(i).unwrap();
            if map.contains_key(&s_i) {
                if map[&s_i] != t_i { return false; }
            } else {
                map.insert(s_i, t_i);
            }
        }
        true
    }

    pub fn is_isomorphic(s: String, t: String) -> bool {
        Solution::_is_isomorphic(&s, &t) && Solution::_is_isomorphic(&t, &s)
    }
}

fn main() {
    for i in &[("ab", "aa"), ("egg", "add"), ("foo", "bar"), ("paper", "title")] {
        println!("{}", Solution::is_isomorphic((*i.0).to_string(), (*i.1).to_string()));
    }
}
