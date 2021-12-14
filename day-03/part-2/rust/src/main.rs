const WIDTH: usize = 12;

pub fn test_bit(from: u32, idx: usize) -> bool {
    (from & (1 << idx)) > 0
}

pub fn get_gas(depths: Vec<u32>, which_gas: &dyn Fn(usize, usize) -> bool) -> u32 {
    (0..WIDTH)
        .rev()
        .scan(depths, |oxy, idx| {
            let selected_bit = which_gas(
                oxy.iter().filter(|depth| test_bit(**depth, idx)).count(),
                (oxy.len() + 1) / 2,
            );

            *oxy = oxy
                .iter()
                .copied()
                .filter(|depth| test_bit(*depth, idx) == selected_bit)
                .collect::<Vec<u32>>();

            oxy.first().copied()
        })
        .last()
        .unwrap()
}

pub fn main() {
    let depths: Vec<u32> = std::include_str!(/*"../sample_input.txt") */ "../../../input.txt")
        .lines()
        .map(|line| u32::from_str_radix(line, 2).unwrap())
        .collect();

    let oxygen = get_gas(depths.clone(), &|count_ones, majority| {
        count_ones >= majority
    });
    let co2 = get_gas(depths.clone(), &|count_ones, minority| {
        count_ones < minority
    });

    println!("Oxygen: {}", oxygen);
    println!("CO2: {}", co2);
    println!("Oxygen x CO2: {}", oxygen * co2);
}
