package main

import (
	"fmt"
	"math"
)

func main() {
	var N int
	fmt.Scan(&N)
	times := make([][]int, N + 3)
	for i := 0; i < N + 3; i++ {
		times[i] = make([]int, 3)
	}
	dp := make([]int, N + 3)
	for i := 0; i < 3; i++ {
		dp[i] = 0
		for j := 0; j < 3; j++ {
			times[i][j] = math.MaxInt
		}
	}
	for i := 3; i < N + 3; i++ {
		fmt.Scan(&times[i][0], &times[i][1], &times[i][2])
		dp[i] = times[i][0] + dp[i - 1]
		if dp[i] > times[i - 1][1] + dp[i - 2] {
			dp[i] = times[i - 1][1] + dp[i - 2]
		}
		if dp[i] > times[i - 2][2] + dp[i - 3] {
			dp[i] = times[i - 2][2] + dp[i - 3]
		}
	}
	fmt.Println(dp[N + 2])
}
