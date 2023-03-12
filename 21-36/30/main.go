package main

import (
	"fmt"
	"math"
)

func main() {
	var N int
	fmt.Scan(&N)
	seqN := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&seqN[i])
	}
	var M int
	fmt.Scan(&M)
	seqM := make([]int, M)
	for i := 0; i < M; i++ {
		fmt.Scan(&seqM[i])
	}
	dp := make([][]int, N + 1)
	for i := 0; i <= N; i++ {
		dp[i] = make([]int, M + 1)
		dp[i][0] = 0
	}
	for j := 1; j <= M; j++ {
		dp[0][j] = 0
	}
	for i := 1; i <= N; i++ {
		for j := 1; j <= M; j++ {
			if seqN[i - 1] == seqM[j - 1] {
				dp[i][j] = dp[i - 1][j - 1] + 1
			} else {
				dp[i][j] = int(math.Max(
					float64(dp[i - 1][j]),
					float64(dp[i][j - 1]),
				))
			}
		}
	}
	i, j := N, M
	defer fmt.Println()
	for i > 0 && j > 0{
		if seqN[i - 1] == seqM[j - 1] {
			defer fmt.Printf("%d ", seqN[i - 1])
			i--
			j--
		} else if dp[i - 1][j] > dp[i][j - 1] {
			i--
		} else {
			j--
		}
	}
}
