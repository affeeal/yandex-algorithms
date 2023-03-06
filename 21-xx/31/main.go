package main

import (
	"bufio"
	"container/list"
	"fmt"
	"os"
)

// TODO: use adjacency matrix instead of list

var count = 0

func DFS(ls *[]*list.List, i int, visited *[]bool) {
	(*visited)[i] = true
	count++
	for e := (*ls)[i].Front(); e != nil; e = e.Next() {
		if (*visited)[e.Value.(int)] == false {
			DFS(ls, e.Value.(int), visited)
		}
	}
}

func main() {
	in := bufio.NewReader(os.Stdin)
	var N, M int
	fmt.Fscanf(in, "%d %d\n", &N, &M)
	ls := make([]*list.List, N + 1)
	// adjacencyList[0] is not used
	for i := 1; i < N + 1; i++ {
		ls[i] = list.New()
	}
	for i := 0; i < M; i++ {
		var u, v int
		fmt.Fscanf(in, "%d %d\n", &u, &v)
		ls[u].PushBack(v)
		if u != v {
			ls[v].PushBack(u)
		}
	}
	visited := make([]bool, N + 1)
	for i := 1; i < N + 1; i++ {
		visited[i] = false
	}
	DFS(&ls, 1, &visited)
	out := bufio.NewWriter(os.Stdout)
	fmt.Fprintf(out, "%d\n", count)
	for i := 1; i < N + 1; i++ {
		if visited[i] == true {
			fmt.Fprintf(out, "%d ", i)
		}
	}
	fmt.Fprintln(out)
	out.Flush()
}
