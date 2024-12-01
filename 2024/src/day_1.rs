use std::fs::read_to_string;

fn read_lines(filename: &str) -> Vec<String> {
    read_to_string(filename)
        .unwrap()
        .lines()
        .map(String::from)
        .collect()
}

fn calculate_distance(mut left_array: Vec<i32>, mut right_array: Vec<i32>) -> i32 {
    let mut total_distance = 0;

    left_array.sort();
    right_array.sort();

    for i in 0..left_array.len() {
        let distance = left_array[i] - right_array[i];

        total_distance += distance.abs();
    }

    return total_distance;
}

fn calculate_similarity(left_array: Vec<i32>, right_array: Vec<i32>) -> i32 {
    let mut total_similarity_score: i32 = 0;
    
    for i in left_array {
        let similarity_score = right_array.iter().filter(|&&x| x == i).count();

        total_similarity_score += similarity_score as i32 * i;
    }

    return total_similarity_score;
}

pub fn day_1(filename: &str) {
    let mut left_array: Vec<i32> = Vec::new();
    let mut right_array: Vec<i32> = Vec::new();

    let lines = read_lines(filename);

    for line in lines {
        let numbers: Vec<i32> = line
            .split_whitespace()
            .map(|s| s.parse().unwrap())
            .collect();
        
        left_array.push(numbers[0]);
        right_array.push(numbers[1]);
    }

    let total_distance = calculate_distance(left_array.clone(), right_array.clone());

    let similarity_score = calculate_similarity(left_array, right_array);

    println!("==== Day one of Advent of Code ====");
    println!("Part One :");
    println!("\tTotal distance: {}", total_distance);
    println!("Part Two :");
    println!("\tSimilarity score: {}", similarity_score);
    println!("===================================");
}