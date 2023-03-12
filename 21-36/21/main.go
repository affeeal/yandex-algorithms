package main

import (
	"fmt"
	"math"
)

func main() {
	var N int
	fmt.Scan(&N)
	size := int(math.Max(float64(N), 3))
	dp := make([]int, size);
	dp[0] = 2;
	dp[1] = 4;
	dp[2] = 7;
	for i := 3; i < N; i++ {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3]
	}
	fmt.Println(dp[N - 1])
}
