package days

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func Day1() {
	input, err := os.ReadFile("inputs/day1")
	if err != nil {
		fmt.Println("Error opening file")
		fmt.Println(err)
		return
	}

	lines := strings.Split(string(input), "\n")
	sum := 0
	frequencies := make(map[int]bool)

	for {
		for _, line := range lines {
			if line == "" {
				continue
			}
			number, err := strconv.Atoi(line)
			if err != nil {
				fmt.Println("Error parsing number")
				fmt.Println(err)
				return
			}

			sum += number

			if frequencies[sum] {
				fmt.Println("First frequency reached twice: ", sum)
				return
			}

			frequencies[sum] = true
		}
	}
}
