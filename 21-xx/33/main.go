package main

import (
	"bufio"
	"container/list"
	"fmt"
	"os"
)

type Vertex struct {
	index int
	command int
}

func DFS(u *Vertex, l *[]*list.List, command int) bool {
	u.command = command
	for e := (*l)[u.index].Front(); e != nil; e = e.Next() {
		v := e.Value.(*Vertex)
		if v.command == -1 {
			if verdict := DFS(v, l, 3 - command); verdict == false {
				return false
			}
		} else if v.command == command {
			return false
		}
	}
	return true
}

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	var N, M int
	fmt.Fscanf(in, "%d %d\n", &N, &M)
	vertices := make([]*Vertex,    N)
	adjList  := make([]*list.List, N)
	for i := 0; i < N; i++ {
		vertices[i] = new(Vertex)
		vertices[i].index = i
		vertices[i].command = -1

		adjList[i] = list.New()
	}

	for i := 0; i < M; i++ {
		var u, v int
		fmt.Fscanf(in, "%d %d\n", &u, &v)
		adjList[u - 1].PushBack(vertices[v - 1])
		adjList[v - 1].PushBack(vertices[u - 1])
	}

	var verdict bool
	for _, u := range vertices {
		if u.command == -1 {
			if verdict = DFS(u, &adjList, 1); verdict == false {
				break
			}
		}
	}
	
	if verdict == false {
		fmt.Fprintln(out, "NO")
	} else {
		fmt.Fprintln(out, "YES")
	}
}
