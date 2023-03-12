#include <iostream>
#include <vector>
#include <queue>

struct Vertex {
  int index;
  int length;
  
  Vertex() : index(-1), length(-1) {}
};

int main() {
  int N;
  std::cin >> N;
  
  std::vector<std::vector<int>> adj_matrix(N);
  for (auto& row : adj_matrix) {
    row.resize(N);
    for (auto& is_adj : row)
      std::cin >> is_adj;
  }
  
  int start, end;
  std::cin >> start >> end;

  std::vector<Vertex> vertices(N);
  for (auto i = 0; i < N; i++)
    vertices[i].index = i;
  vertices[end - 1].length = 0;
  
  std::queue<int> q;
  q.push(end - 1);
  
  std::vector<int> came_from(N, -1);
  while (!q.empty()) {
    for (auto i = 0; i < N; i++) {
      if (adj_matrix[q.front()][i] == 0)
        continue;
      if (vertices[i].length == -1) {
        vertices[i].length = vertices[q.front()].length + 1;
        came_from[i] = q.front();
        q.push(i);
      }
    }
    q.pop();
  }

  std::cout << vertices[start - 1].length << std::endl;
  if (came_from[start - 1] == -1)
    return 0;
  
  for (auto i = start - 1; i != -1; i = came_from[i])
    std::cout << i + 1 << ' ';
  std::cout << std::endl;
}
