#include <array>
#include <iostream>
#include <queue>
#include <vector>

struct Vertex {
  int x;
  int y;
  int length;

  Vertex() : x(-1), y(-1), length(-1) {}
};

int main() {
  int N, M, S, T, Q;
  std::cin >> N >> M >> S >> T >> Q;

  // matrix[i][0], matrix[0][j] are not used
  std::vector<std::vector<Vertex>> matrix(N + 1);
  for (auto i = 1; i <= N; i++) {
    matrix[i].resize(M + 1);
    for (auto j = 1; j <= M; j++) {
      matrix[i][j].x = i;
      matrix[i][j].y = j;
    }
  }
  matrix[S][T].length = 0;

  std::vector<Vertex*> vertices(Q);
  for (auto& u : vertices) {
    int x, y;
    std::cin >> x >> y;
    u = &matrix[x][y];
  }

  std::array<std::pair<int, int>, 8> delta = {
    std::make_pair(-2, -1),
    std::make_pair(-2,  1),
    std::make_pair(-1,  2),
    std::make_pair( 1,  2),
    std::make_pair( 2,  1),
    std::make_pair( 2, -1),
    std::make_pair( 1, -2),
    std::make_pair(-1, -2),
  };
  
  std::queue<Vertex*> q;
  q.push(&matrix[S][T]);
  
  while (!q.empty()) {
    auto u = q.front();
    for (const auto& [x, y] : delta) {
      if (1 <= u->x + x && u->x + x <= N &&
          1 <= u->y + y && u->y + y <= M &&
          matrix[u->x + x][u->y + y].length == -1) {
        q.push(&matrix[u->x + x][u->y + y]);
        q.back()->length = u->length + 1;
      }
    }
    q.pop();
  }

  int sum = 0;
  for (const auto& u : vertices) {
    if (u->length == -1) {
      sum = -1;
      break;
    }
    sum += u->length;
  }
  std::cout << sum << std::endl;
}
