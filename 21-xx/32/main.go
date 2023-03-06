package main

import (
	"bufio"
	"container/list"
	"fmt"
	"os"
)

func DFS(adjacencyList *[]*list.List, i int, visited *[]bool, components *[]*list.List, number int) {
	(*visited)[i] = true
	(*components)[number].PushBack(i)
	for e := (*adjacencyList)[i].Front(); e != nil; e = e.Next() {
		if (*visited)[e.Value.(int)] == false {
			DFS(adjacencyList, e.Value.(int), visited, components, number)
		}
	}
}

func main() {
	in := bufio.NewReader(os.Stdin)
	var N, M int
	fmt.Fscanf(in, "%d %d\n", &N, &M)
	adjacencyList := make([]*list.List, N)
	for i := 0; i < N; i++ {
		adjacencyList[i] = list.New()
	}
	for i := 0; i < M; i++ {
		var u, v int
		fmt.Fscanf(in, "%d %d\n", &u, &v)
		adjacencyList[u - 1].PushBack(v - 1)
		if u != v {
			adjacencyList[v - 1].PushBack(u - 1)
		}
	}
	number := 0
	components := make([]*list.List, 0)
	visited := make([]bool, N)
	for i := 0; i < N; i++ {
		if visited[i] == false {
			components = append(components, list.New())
			DFS(&adjacencyList, i, &visited, &components, number)
			number++
		}
	}
	out := bufio.NewWriter(os.Stdout)
	fmt.Fprintf(out, "%d\n", number)
	for i := 0; i < number; i++ {
		fmt.Fprintf(out, "%d\n", components[i].Len())
		for e := components[i].Front(); e != nil; e = e.Next() {
			fmt.Fprintf(out, "%d ", e.Value.(int) + 1)
		}
		fmt.Fprintln(out)
	}
	out.Flush()
}
