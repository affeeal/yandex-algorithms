package main

import (
	"fmt"
	"math"
)

func main() {
	var N, M int
	fmt.Scan(&N, &M)
	matrix := make([][]int, N)
	for i := 0; i < N; i++ {
		matrix[i] = make([]int, M)
		for j := 0; j < M; j++ {
			fmt.Scan(&matrix[i][j])
		}
	}
	dp := make([][]int, N + 1)
	for i := 0; i <= N; i++ {
		dp[i] = make([]int, M + 1)
		dp[i][0] = 0
	}
	for i := 1; i <= M; i++ {
		dp[0][i] = 0
	}
	for i := 1; i <= N; i++ {
		for j := 1; j <= M; j++ {
			dp[i][j] = int(math.Max(
				float64(dp[i - 1][j]),
				float64(dp[i][j - 1]),
			)) + matrix[i - 1][j - 1]
		}
	}
	fmt.Println(dp[N][M])
	defer fmt.Println()
	i, j := N, M
	for i != 1 || j != 1 {
		if dp[i][j] - matrix[i - 1][j - 1] == dp[i - 1][j] {
			defer fmt.Print("D ")
			i--
		} else {
			defer fmt.Print("R ")
			j--
		}
	}
}
