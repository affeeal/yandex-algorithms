package main

import (
	"fmt"
	"math"
)

func main() {
	var N, M int
	fmt.Scan(&N, &M)
	dp := make ([][]int, N + 1)
	for i := 0; i <= N; i++ {
		dp[i] = make ([]int, M + 1)
		dp[i][0] = math.MaxInt
	}
	dp[0][1] = 0 // base
	for i := 2; i <= M; i++ {
		dp[0][i] = math.MaxInt
	}
	for i := 1; i <= N; i++ {
		for j := 1; j <= M; j++ {
			var weight int
			fmt.Scan(&weight)
			dp[i][j] = int(math.Min(
				float64(dp[i - 1][j]),
				float64(dp[i][j - 1]),
			)) + weight
		}
	}
	fmt.Println(dp[N][M])
}
