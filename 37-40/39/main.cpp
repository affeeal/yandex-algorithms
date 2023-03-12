#include <array>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>

struct Vertex {
  int x;
  int y;
  int z;
  int length;

  Vertex() : x(-1), y(-1), z(-1), length(-2) {}
};

int main() {
  int N;
  std::cin >> N;
  
  std::queue<Vertex*> q;
  std::vector<std::vector<std::vector<Vertex>>> cube(N);
  for (auto i = 0; i < N; i++) {
    cube[i].resize(N);
    std::cin.ignore(1, '\n');
    
    for (auto j = 0; j < N; j++) {
      cube[i][j].resize(N);
      
      for (auto k = 0; k < N; k++) {
        cube[i][j][k].x = i;
        cube[i][j][k].y = j;
        cube[i][j][k].z = k;
        
        char c;
        std::cin >> c;
        if (c == '.') {
          cube[i][j][k].length = -1;
        } else if (c == 'S') {
          cube[i][j][k].length = 0;
          q.push(&cube[i][j][k]);
        }
      }
      std::cin.ignore(1, '\n');
    }
  }

  std::array<std::array<int, 3>, 6> delta {{
    { -1,  0,  0 },
    {  1,  0,  0 },
    {  0, -1,  0 },
    {  0,  1,  0 },
    {  0,  0, -1 },
    {  0,  0,  1 }
  }};

  while (!q.empty()) {
   auto u = q.front();
   auto x = u->x;
   auto y = u->y;
   auto z = u->z;
   for (const auto [dx, dy, dz] : delta) {
     if (0 <= x + dx && x + dx <= N - 1 &&
         0 <= y + dy && y + dy <= N - 1 &&
         0 <= z + dz && z + dz <= N - 1 &&
         cube[x + dx][y + dy][z + dz].length == -1) {
       q.push(&cube[x + dx][y + dy][z + dz]);
       q.back()->length = u->length + 1;
     }
   }
   q.pop();
  }
 
  int length = INT_MAX;
  for (const auto& line : cube[0])
    for (const auto& u : line)
      if (u.length >= 0 && u.length < length)
        length = u.length;

  std::cout << length << std::endl;
}
