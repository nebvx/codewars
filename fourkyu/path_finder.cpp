#include <iostream>
#include <string>
#include <queue>

using namespace std;

bool path_finder(string maze) {
  std::vector<std::vector<int>> matrix(1);
  int m_size = {0};
  for (size_t i {0}; i < maze.size(); ++i) {
    if (maze[i] == '.') matrix[m_size].push_back(1);
    if (maze[i] == 'W' )matrix[m_size].push_back(0);
    if (maze[i] == '\n') {
      ++m_size;
      matrix.push_back({});
    }
  }
  
  std::queue<std::pair<int, int>> q;
  q.push({0,0});
  std::vector<std::vector<int>> visited (matrix.size(), std::vector<int>(matrix[0].size(), 0));
  std::vector<std::pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();
    if (x == m_size && y == m_size) return true;
    for (auto [dx, dy] : directions) {
      int new_x = x + dx;
      int new_y = y + dy;
      if (new_x >= 0 && new_x <= m_size && new_y >= 0 && new_y <= m_size) {
        if (matrix[new_x][new_y] == 1 && visited[new_x][new_y] == 0) {
          q.push({new_x, new_y});
          visited[new_x][new_y] = 1;
        }
      }
    }
  }
  return false;
}