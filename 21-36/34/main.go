package main

import (
	"bufio"
	"container/list"
	"fmt"
	"os"
)

const (
	WHITE = iota
	GRAY
	BLACK
)

type Vertex struct {
	index int
	color int
	adjacent *list.List
}

func DFS(u *Vertex, sorted *list.List) bool {
	u.color = GRAY
	for e := u.adjacent.Front(); e != nil; e = e.Next() {
		v := e.Value.(*Vertex)
		if v.color == WHITE {
			if verdict := DFS(v, sorted); verdict == false {
				return false
			}
		} else if v.color == GRAY {
			return false
		}
	}
	u.color = BLACK
	sorted.PushFront(u)
	return true
}

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	var N, M int
	fmt.Fscanf(in, "%d %d\n", &N, &M)
	vertices := make([]*Vertex, N)
	for i := 0; i < N; i++ {
		vertices[i] = new(Vertex)
		vertices[i].index = i
		vertices[i].color = WHITE
		vertices[i].adjacent = list.New()
	}

	for i := 0; i < M; i++ {
		var u, v int
		fmt.Fscanf(in, "%d %d\n", &u, &v)
		vertices[u - 1].adjacent.PushBack(vertices[v - 1])
	}

	var verdict bool
	sorted := list.New()
	for _, u := range vertices {
		if u.color == WHITE {
			if verdict = DFS(u, sorted); verdict == false {
				break
			}
		}
	}

	if verdict == false {
		fmt.Fprintln(out, -1)
		return
	}

	for e := sorted.Front(); e != nil; e = e.Next() {
		fmt.Fprintf(out, "%d ", e.Value.(*Vertex).index + 1)
	}
	fmt.Fprintln(out)
}
