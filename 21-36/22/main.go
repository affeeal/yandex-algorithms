package main

import "fmt"

func main() {
	var N, K int	
	fmt.Scan(&N, &K)
	dp := make([]int, K - 1 + N)
	for i := 0; i < K - 1; i++ {
		dp[i] = 0
	}
	dp[K - 1] = 1
	sum := 1
	for i := K; i < K - 1 + N; i++ {
		dp[i] = sum
		sum += dp[i] - dp[i - K]
	}
	fmt.Println(dp[N + K - 2])
}
