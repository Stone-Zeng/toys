// 79. Word Search
// https://leetcode.com/problems/word-search/

struct Solution {}

impl Solution {
    pub fn exist(board: Vec<Vec<char>>, word: String) -> bool {
        SolutionHelper::new(board, word).exist()
    }
}

struct SolutionHelper {
    board: Vec<Vec<char>>,
    x_len: usize,
    y_len: usize,
    points: Vec<Point>,
    word: Vec<u8>,
    word_ptr: usize,
}

impl SolutionHelper {
    fn new(board: Vec<Vec<char>>, word: String) -> Self {
        let x_len = board.len();
        let y_len = board[0].len();
        Self {
            board,
            x_len,
            y_len,
            points: Vec::new(),
            word: word.as_bytes().to_vec(),
            word_ptr: 0,
        }
    }

    fn exist(&mut self) -> bool {
        let init_char = self.word[0] as char;
        for i in 0..self.x_len {
            for j in 0..self.y_len {
                if self.board[i][j] == init_char {
                    self.word_ptr = 1;
                    if self.check_adjacent(i, j) {
                        return true;
                    }
                }
            }
        }
        false
    }

    #[allow(mutable_borrow_reservation_conflict)]
    fn check_adjacent(&mut self, i: usize, j: usize) -> bool {
        self.points.push(Point::new(i, j));
        while self.word_ptr < self.word.len() {
            if self.points.is_empty() {
                return false;
            }
            let p = self.points.last().unwrap();
            let c = self.word[self.word_ptr] as char;
            macro_rules! branch {
                ($condition:expr; $x:expr, $y:expr) => {
                    if $condition
                        && !self.points.contains(&Point::new($x, $y))
                        && self.board[$x][$y] == c
                    {
                        self.points.push(Point::new($x, $y));
                        self.word_ptr += 1;
                    } else {
                        self.next();
                    }
                };
            }
            match p.flag {
                0 => branch!(p.x > 0;              p.x - 1, p.y),
                1 => branch!(p.y < self.y_len - 1; p.x,     p.y + 1),
                2 => branch!(p.x < self.x_len - 1; p.x + 1, p.y),
                3 => branch!(p.y > 0;              p.x,     p.y - 1),
                _ => unreachable!(),
            }
        }
        true
    }

    fn next(&mut self) {
        if let Some(p) = self.points.last_mut() {
            match p.flag {
                0 | 1 | 2 => {
                    p.flag += 1;
                }
                3 => {
                    self.points.pop();
                    self.word_ptr -= 1;
                    self.next();
                }
                _ => unreachable!(),
            }
        }
    }
}

#[derive(Debug, Clone, Copy)]
struct Point {
    x: usize,
    y: usize,
    flag: u8,
}

impl Point {
    fn new(x: usize, y: usize) -> Self {
        Self { x, y, flag: 0 }
    }
}

impl PartialEq for Point {
    fn eq(&self, other: &Self) -> bool {
        self.x == other.x && self.y == other.y
    }
}

fn main() {
    let board = vec![
        vec!['A', 'B', 'C', 'E'],
        vec!['S', 'F', 'C', 'S'],
        vec!['A', 'D', 'E', 'E'],
    ];
    for word in &["A", "X", "ABCCED", "SEE", "ABCB", "ABCEE"] {
        println!(
            "{}:\t{}",
            word,
            Solution::exist(board.clone(), word.to_string())
        );
    }
}
