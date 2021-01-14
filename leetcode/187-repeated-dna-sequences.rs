// 187. Repeated DNA Sequences
// https://leetcode.com/problems/repeated-dna-sequences/

use std::collections::HashMap;

struct Solution {}

impl Solution {
    pub fn find_repeated_dna_sequences(s: String) -> Vec<String> {
        if s.len() <= 10 {
            return vec![];
        };
        let mut map: HashMap<&str, usize> = HashMap::new();
        (0..=(s.len() - 10)).for_each(|i| {
            let x = &s[i..(i + 10)];
            if let Some(n) = map.get_mut(x) {
                *n += 1;
            } else {
                map.insert(x, 1);
            }
        });
        map.iter()
            .filter(|(_, &v)| v >= 2)
            .map(|(&k, _)| k.to_string())
            .collect()
    }
}

fn main() {
    for i in &[
        "",
        "AAAAAAAAAAA",
        "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",
        "AAAAAAAAAAAAA",
    ] {
        println!("{:?}", Solution::find_repeated_dna_sequences(i.to_string()));
    }
}
