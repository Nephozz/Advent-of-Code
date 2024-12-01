package days

import (
	"errors"
	"fmt"
	"os"
	"strings"
)

func Day2Part1() {
	input, err := os.ReadFile("inputs/day2")
	if err != nil {
		fmt.Println("Error, couldn't read the file!: ", err)
		return
	}

	lines := strings.Split(string(input), "\n")
	var twoTimes, threeTimes int

	for _, line := range lines {
		letterCounts := make(map[rune]int)

		for _, letter := range line {
			letterCounts[letter]++
		}

		twoFound, threeFound := false, false

		for _, count := range letterCounts {
			if count == 2 && !twoFound {
				twoTimes++
				twoFound = true
			}
			if count == 3 && !threeFound {
				threeTimes++
				threeFound = true
			}
		}
	}

	checksum := twoTimes * threeTimes

	fmt.Println("Checksum is:", checksum)
}

func Day2Part2() {
	input, err := os.ReadFile("inputs/day2")
	if err != nil {
		fmt.Println("Error, couldn't read the file!: ", err)
		return
	}

	lines := strings.Split(string(input), "\n")

	for i := 0; i < len(lines); i++ {
		for j := i + 1; j < len(lines); j++ {
			commonLetters, nb, err := compareStrings(lines[i], lines[j])
			if err != nil {
				fmt.Println(err)
				return
			}

			if nb == len(lines[i])-1 {
				fmt.Println(string(commonLetters))
			}
		}
	}

	fmt.Println("Finished!")
}

func compareStrings(a, b string) ([]rune, int, error) {
	if len(a) != len(b) {
		return nil, 0, errors.New("strings must be the same size")
	}

	var similarLetters []rune
	nbSimilar := 0

	for i := 0; i < len(a); i++ {
		if a[i] == b[i] {
			similarLetters = append(similarLetters, rune(a[i]))
			nbSimilar++
		}
	}

	return similarLetters, nbSimilar, nil
}
