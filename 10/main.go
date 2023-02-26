package main

import "fmt"

const SIZE int = 26

func main() {
	var s string
	fmt.Scan(&s)
	var counts [SIZE]int
	for i := 0; i < SIZE; i++ {
		counts[i] = 0
	}
	n := len(s)
	left := 0
	right := n - 1
	for left <= right {
		count := (n - left) * (left + 1)
		counts[s[left] - 'a'] += count
		if left != right {
			counts[s[right] - 'a'] += count
		}
		left++;
		right--;
	}
	for i := 0; i < SIZE; i++ {
		if (counts[i] != 0) {
			fmt.Printf("%c: %d\n", i + 'a', counts[i])
		}
	}
}
