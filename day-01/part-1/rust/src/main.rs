fn main() {
    let input = std::include_str!("../../../input.txt");
    let (_, count_inc) = input.lines().map(|x| x.parse::<usize>().unwrap()).fold(
        (std::usize::MAX, 0),
        |(prev, count), x| if x > prev { (x, count + 1) } else { (x, count) },
    );

    println!("Total number of increases: {}", count_inc);
}
