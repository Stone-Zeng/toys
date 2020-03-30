// 71. Simplify Path
// https://leetcode.com/problems/simplify-path/

struct Solution { }

impl Solution {
    pub fn simplify_path(path: String) -> String {
        let mut v: Vec<&str> = path.split("/").collect();
        v.retain(|&x| !(x == "" || x == "."));
        if !v.is_empty() {
            let mut i: usize = 0;
            loop {
                if v[i] == ".." {
                    v.remove(i);
                    if i >= 1 {
                        i -= 1;
                        v.remove(i);
                    }
                } else {
                    i += 1;
                }
                if i == v.len() { break; }
            }
        }
        format!("/{}", v.join("/"))
    }
}

fn main() {
    for i in &[
        ("/home/", "/home"),
        ("/../", "/"),
        ("/home//foo/", "/home/foo"),
        ("/a/./b/../../c/", "/c"),
        ("/a/../../b/../c//.//", "/c"),
        ("/a//b////c/d//././/..", "/a/b/c"),
    ] {
        println!("{}", Solution::simplify_path(i.0.to_string()) == i.1);
    }
}
