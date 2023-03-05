package main

import "fmt"

func main() {
	var N, M int
	fmt.Scan(&N, &M)
	dp := make([][]int, N + 2)
	for i := 0; i < N + 2; i++ {
		dp[i] = make([]int, M + 2)
		for j := 0; j < M + 2; j++ {
			dp[i][j] = 0
		}
	}
	dp[0][1] = 1 // base
	i, j := 2, 2
	for i < N + 2 && j < M + 2 {
		k, l := i, j
		for k < N + 2 && l < M + 2 {
			dp[k][l] = dp[k - 2][l - 1] + dp[k - 1][l - 2]
			k += 1
			l += 2
		}
		i += 2
		j += 1
	}
	fmt.Println(dp[N + 1][M + 1])
}
