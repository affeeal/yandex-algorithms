package main

import (
	"fmt"
	"math"
)

func main() {
	var N int
	fmt.Scan(&N)
	prices := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&prices[i])
	}
	dp := make([][]int, N + 1)
	for i := 0; i < N + 1; i++ {
		dp[i] = make([]int, N + 3)
		dp[i][0] = math.MaxInt
		dp[i][N + 2] = math.MaxInt
	}
	for j := 1; j < N + 2; j++ {
		dp[0][j] = math.MaxInt
	}
	dp[0][1] = 0 // base
	for i := 1; i < N + 1; i++ {
		for j := 1; j < N + 2; j++ {
			if prices[i - 1] > 100 {
				if dp[i - 1][j - 1] == math.MaxInt {
					dp[i][j] = dp[i - 1][j + 1]
				} else {
					dp[i][j] = int(math.Min(
						float64(dp[i - 1][j - 1] + prices[i - 1]),
						float64(dp[i - 1][j + 1]),
					))
				}
			} else {
				if dp[i - 1][j] == math.MaxInt {
					dp[i][j] = dp[i - 1][j + 1]
				} else {
					dp[i][j] = int(math.Min(
						float64(dp[i - 1][j] + prices[i - 1]),
						float64(dp[i - 1][j + 1]),
					))
				}
			}
		}
	}
	jMin := 1
	coupons := 0
	for dp[N][jMin] == math.MaxInt { jMin++ }
	for dp[N][jMin] == dp[N][jMin + 1] { jMin++ }
	for i, j := N, jMin; i > 1; i-- {
		if dp[i][j] == dp[i - 1][j + 1] {
			defer fmt.Println(i)
			coupons++
			j++
		} else if prices[i - 1] > 100 {
			j--
		}
	}
	fmt.Println(dp[N][jMin])
	fmt.Println(jMin - 1, coupons)
}
