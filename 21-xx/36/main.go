package main

import (
	"bufio"
	"container/list"
	"fmt"
	"os"
)

type Vertex struct {
  index int
  length int
}

func main() {
  in := bufio.NewReader(os.Stdin)
  out := bufio.NewWriter(os.Stdout)
  defer out.Flush()

  var N int
  fmt.Fscanf(in, "%d\n", &N)
  adjMatrix := make([][]bool, N)
  for i := 0; i < N; i++ {
    adjMatrix[i] = make([]bool, N)
    var adj int
    for j := 0; j < N - 1; j++ {
      fmt.Fscanf(in, "%d ", &adj)
      if adj == 1 { adjMatrix[i][j] = true }
    }
    fmt.Fscanf(in, "%d\n", &adj)
    if adj == 1 { adjMatrix[i][N - 1] = true }
  }

  vertices := make([]*Vertex, N)
  for i := 0; i < N; i++ {
    vertices[i] = new(Vertex)
    vertices[i].index = i
    vertices[i].length = -1
  }

  var start, end int
  fmt.Fscanf(in, "%d %d\n", &start, &end)

  l := make([]*list.List, 1)
  l[0] = list.New()
  l[0].PushBack(vertices[start - 1])

  vertices[start - 1].length = 0
  
  for {
    curr := len(l)
    prev := curr - 1
    l = append(l, list.New())
    
    for e := l[prev].Front(); e != nil; e = e.Next() {
      u := e.Value.(*Vertex)
      
      for i, isAdj := range adjMatrix[u.index] {
        if isAdj == false { continue }
        v := vertices[i]
        
        if v.length == -1 {
          v.length = curr
          l[curr].PushBack(v)
        }
      }
    }

    if l[curr].Len() == 0 {
      break
    }
  }
  fmt.Fprintf(out, "%d\n", vertices[end - 1].length)
}
