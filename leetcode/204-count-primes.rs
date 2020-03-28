// 204. Count Primes
// https://leetcode.com/problems/count-primes/

struct Solution { }

impl Solution {
    fn is_prime(n: i32, primes: &Vec<i32>) -> bool {
        for i in primes {
            if n % i == 0 { return false; }
        }
        true
    }

    pub fn count_primes(n: i32) -> i32 {
        if n <= 2 { return 0; }
        if n <= 3 { return 1; }
        if n <= 5 { return 2; }
        if n <= 7 { return 3; }

        let mut max_prime_range = (n as f32).sqrt().floor() as i32;
        if max_prime_range % 2 == 0 {
            max_prime_range += 1;
        }

        let mut count = 0;
        let mut primes = Vec::new();

        for i in (7..=max_prime_range).step_by(2) {
            if i % 3 != 0 && i % 5 != 0 && i % 7 != 0 {
                if Solution::is_prime(i, &primes) {
                    count += 1;
                    primes.push(i);
                }
            }
        }
        for i in (max_prime_range..n).step_by(2) {
            if i % 3 != 0 && i % 5 != 0 && i % 7 != 0 {
                if Solution::is_prime(i, &primes) {
                    count += 1;
                }
            }
        }

        count + 4
    }
}

fn main() {
    for i in &[0, 1, 2, 3, 4, 5, 6, 7, 10, 100, 1000, 1000000] {
        println!("{}: {}", i, Solution::count_primes(*i));
    }
}
