package main

import (
	"fmt"
)

func main() {
	var N int
	fmt.Scan(&N)
	dp := make([]int, N + 1)
	sf := make([]int, N + 1)
	// dp[0], sf[0] are not used
	dp[1] = 0
	sf[1] = 0
	for i := 2; i <= N; i++ {
		dp[i] = dp[i - 1] + 1
		sf[i] = i - 1
		if i % 2 == 0 && dp[i] > dp[i / 2] + 1 {
			dp[i] = dp[i / 2] + 1
			sf[i] = i / 2
		}
		if i % 3 == 0 && dp[i] > dp[i / 3] + 1 {
			dp[i] = dp[i / 3] + 1
			sf[i] = i / 3
		}
	}
	fmt.Println(dp[N])
	defer fmt.Println()
	for i := N; i != 0; i = sf[i] {
		defer fmt.Printf("%d ", i)
	}
}
