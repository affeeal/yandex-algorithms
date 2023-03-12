#include <climits>
#include <iostream>
#include <queue>
#include <vector>

struct Line {
  int index;
  int length;

  Line() : index(-1), length(-1) {}
};

struct Station {
  int index;

  std::vector<Line*> lines;

  Station() : index(-1) {}
};


int main() {
  int N;
  std::cin >> N;

  // vertices[0] is not used
  std::vector<Station> stations(N + 1);
  for (auto i = 1; i <= N; i++)
    stations[i].index = i;

  int M;
  std::cin >> M;

  // lines[0] is not used
  std::vector<Line> lines(M + 1);
  for (auto i = 1; i <= M; i++) {
    lines[i].index = i;
    lines[i].length = -1;
  }

  // adjacency_matrix[i][0], adjacency_matrix[0][j] are not used
  std::vector<std::vector<bool>> adjacency_matrix(
      M + 1, std::vector<bool>(M + 1));
  
  for (auto i = 1; i <= M; i++) {
    int P;
    std::cin >> P;
    
    for (auto j = 0; j < P; j++) {
      int u;
      std::cin >> u;
      
      for (const auto& line : stations[u].lines) {
         adjacency_matrix[i][line->index] = true;
         adjacency_matrix[line->index][i] = true;
      }
      
      stations[u].lines.push_back(&lines[i]);
    }
  }

  int start, end;
  std::cin >> start >> end;

  std::queue<Line*> q;
  for (auto& line : stations[start].lines) {
    line->length = 0;
    q.push(line);
  }

  while (!q.empty()) {
    auto u = q.front();
    for (auto i = 1; i <= M; i++) {
      if (!adjacency_matrix[u->index][i]) continue;
      if (lines[i].length == -1) {
        lines[i].length = u->length + 1;
        q.push(&lines[i]);
      }
    }
    q.pop();
  }

  auto min_length = INT_MAX;
  for (const auto& line : stations[end].lines)
    min_length = std::min(min_length, line->length);

  std::cout << min_length << std::endl;
}
