package main

import (
	"fmt"
)

func main() {
	fmt.Println("longest subsequent string without repeating characters")

	/// abcdefghahskskoej  -- result = abcdefgh , i.e all unique characters

	// i am gonna use sets
	//   012345678
	input := "abcabcbb"
	max := 0
	start := 0
	longestSubstring := ""

	sw := map[rune]struct{}{}

	for end, char := range input {
		// If the character is in the set, remove characters from the start
		for _, ok := sw[char]; ok; _, ok = sw[char] {
			delete(sw, rune(input[start]))
			start++
		}
		// Add the current character to the set
		sw[char] = struct{}{} // Update max length and longest substring if necessary
		if (end - start + 1) > max {
			max = end - start + 1
			longestSubstring = input[start : end+1]
		}

	}
	fmt.Println("Maximum length of substring without repeating characters:", max)
	fmt.Println("Longest substring without repeating characters:", longestSubstring)

}
