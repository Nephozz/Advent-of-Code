package main

import (
	"fmt"
	"os"
	"strconv"

	days "adventofcode2018/days"
)

func main() {
	var day int
	day, err := strconv.Atoi(os.Args[1])

	if err != nil {
		fmt.Println("Can't read input, please provide a number!")
		return
	}

	switch day {
	case 1:
		days.Day1()
	case 2:
		fmt.Print("Part 1 - ")
		days.Day2Part1()
		fmt.Print("Part 2 - ")
		days.Day2Part2()
	default:
		fmt.Println("Invalid day !")
	}
}
