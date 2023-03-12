package main

import (
	"fmt"
	"math"
	"sort"
)

type Xs []int

func (xs Xs) Len() int {
	return len(xs)
}

func (xs Xs) Swap(i, j int) {
	xs[i], xs[j] = xs[j], xs[i]
}

func (xs Xs) Less(i, j int) bool {
	return xs[i] < xs[j]
}

// TODO: replace hardcoded cases with a base

func main() {
	var N int
	fmt.Scan(&N)
	xs := make(Xs, N + 1)
	xs[0] = 0
	for i := 1; i <= N; i++ {
		fmt.Scan(&xs[i])
	}
	sort.Sort(xs)
	dp := make([]int, N + 1)
	// dp[0], dp[1] are not used
	dp[2] = xs[2] - xs[1]
	if N >= 3 {
		dp[3] = xs[3] - xs[1]
	}
	if N >= 4 {
		dp[4] = xs[4] - xs[3] + dp[2]
	}
	for i := 5; i <= N; i++ {
		dp[i] = int(math.Min(
			float64(dp[i - 3] + xs[i] - xs[i - 2]),
			float64(dp[i - 2] + xs[i] - xs[i - 1]),
		))
	}
	fmt.Println(dp[N])
}
