package main

import (
	"bufio"
	"fmt"
	"os"
)

type Vertex struct {
  index int
  depth int
}

func FindCycle(u, parent *Vertex, depth int,
    vertices *[]*Vertex, adjMatrix *[][]bool,
    out *bufio.Writer) (*Vertex, bool) {
  u.depth = depth
  for i, isAdj := range (*adjMatrix)[u.index] {
    if isAdj == false {
      continue
    }
    v := (*vertices)[i]
    if v.depth == 0 {
      cycleStart, isPrinted := FindCycle(v, u, depth + 1,
                                         vertices, adjMatrix, out)
      if cycleStart != nil {
        if cycleStart == u {
          fmt.Fprintf(out, "%d %d\n", v.index + 1, u.index + 1)
          return nil, true
        } else {
          fmt.Fprintf(out, "%d ", v.index + 1)
          return cycleStart, false
        }
      } else if isPrinted == true {
        return nil, true
      }
    } else if v != parent {
      fmt.Fprintln(out, "YES")
      fmt.Fprintf(out, "%d\n", u.depth - v.depth + 1)
      return v, false
    }
  }
  return nil, false
}

func main() {
  in := bufio.NewReader(os.Stdin)
  out := bufio.NewWriter(os.Stdout)
  defer out.Flush()

  var n int
  fmt.Fscanf(in, "%d\n", &n)
  adjMatrix := make([][]bool, n)
  for i := 0; i < n; i++ {
    adjMatrix[i] = make([]bool, n)
    var adj int
    for j := 0; j < n - 1; j++ {
      fmt.Fscanf(in, "%d ", &adj)
      if (adj == 1) {
        adjMatrix[i][j] = true
      } else {
        adjMatrix[i][j] = false
      }
    }
    fmt.Fscanf(in, "%d\n", &adj)
    if adj == 1 {
      adjMatrix[i][n - 1] = true
    } else {
      adjMatrix[i][n - 1] = false
    }
  }

  vertices := make([]*Vertex, n)
  for i := 0; i < n; i++ {
    vertices[i] = new(Vertex)
    vertices[i].index = i
    vertices[i].depth = 0
  }

  var hasCycle bool
  for _, u := range vertices {
    if u.depth == 0 {
      _, hasCycle = FindCycle(u, nil, 1, &vertices, &adjMatrix, out)
      if hasCycle {
        break
      }
    }
  }
  
  if !hasCycle {
    fmt.Fprintln(out, "NO")
  }
}
