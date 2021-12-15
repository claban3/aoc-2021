use std::cmp;
use std::collections::HashMap;

fn main() {
    // non-sense parsing done
    let lines = std::include_str!("../../../input.txt").lines().map(|l| {
        l.split("->")
            .map(|x| {
                x.split(",")
                    .map(|k| k.trim().parse::<u32>().unwrap())
                    .collect::<Vec<_>>()
            })
            .map(|pts| (pts[0], pts[1]))
            .collect::<Vec<_>>()
    });

    let mut pt_counts = HashMap::new();
    lines.for_each(|l| {
        let (lx, ly) = l[0];
        let (rx, ry) = l[1];
        match (lx == rx, ly == ry) {
            // horizontal
            (true, false) => {
                let from = cmp::min(ly, ry);
                let to = cmp::max(ly, ry) + 1;
                (from..to).for_each(|i| {
                    *pt_counts.entry((lx, i)).or_insert(0) += 1;
                });
            }
            // vertical
            (false, true) => {
                let from = cmp::min(lx, rx);
                let to = cmp::max(lx, rx) + 1;
                (from..to).for_each(|i| {
                    *pt_counts.entry((i, ry)).or_insert(0) += 1;
                });
            }
            _ => {}
        }
    });
    let total_counts = pt_counts.values().filter(|count| **count >= 2).count();
    println!("Overlaps greater than two: {}", total_counts);
}
