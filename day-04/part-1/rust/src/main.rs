use std::collections::HashSet;

const BOARD_SIZE: usize = 5 * 5;

struct BingoBoard {
    board: Vec<u32>,
}

impl BingoBoard {
    fn final_score<F: Fn(u32) -> bool>(&self, is_picked: F) -> u32 {
        self.board.iter().filter(|n| !is_picked(**n)).sum()
    }

    fn has_won<F: Fn(u32) -> bool>(&self, is_picked: F) -> bool {
        (0..5).any(|r| self.win_across(r, &is_picked)) || 
        (0..5).any(|c| self.win_down(c, &is_picked)) || 
        self.win_diag(&is_picked)
    }

    fn win_across<F: Fn(u32) -> bool>(&self, row: usize, is_picked: F) -> bool {
        self.board[row..row + 5].iter().all(|num| is_picked(*num))
    }

    fn win_down<F: Fn(u32) -> bool>(&self, col: usize, is_picked: F) -> bool {
        self.board
            .iter()
            .skip(col)
            .step_by(5)
            .take(5)
            .all(|num| is_picked(*num))
    }

    fn win_diag<F: Fn(u32) -> bool>(&self, is_picked: F) -> bool {
        let down = self
            .board
            .iter()
            .step_by(6)
            .take(5)
            .all(|num| is_picked(*num));

        let up = self
            .board
            .iter()
            .skip(4)
            .step_by(6)
            .take(5)
            .all(|num| is_picked(*num));
        
        down || up
    }
}

fn main() {
    let mut parsed = include_str!("../sample-input.txt").split_whitespace();
    let bingo_balls = parsed
        .next()
        .unwrap()
        .split(',')
        .map(|n| n.parse::<u32>().unwrap())
        .collect::<Vec<_>>();

    let bingo_boards: Vec<BingoBoard> = parsed
        .map(|n| n.parse::<u32>().unwrap())
        .collect::<Vec<_>>()
        .chunks(BOARD_SIZE)
        .map(|chunk| BingoBoard {
            board: chunk.to_vec(),
        })
        .collect();

    let mut picked_balls = HashSet::new();
    for ball in bingo_balls {
        picked_balls.insert(ball);

        let is_ball_picked = |n: u32| picked_balls.contains(&n);
        for board in &bingo_boards {
            if board.has_won(is_ball_picked) {
                let final_score = board.final_score(is_ball_picked);
                println!("Winning number: {}", ball);
                println!("Final score: {}", final_score);
                println!("Product: {}", final_score * ball);
                return;
            }
        }
    }
}
