#include <vector>

std::vector<int> snail(const std::vector<std::vector<int>> &snail_map) {
  std::vector<int> ret;
  if (snail_map.empty() || snail_map[0].empty()) {
    return ret;
  }

  size_t top{0}, right{snail_map[0].size()}, down{right}, left{0};
  while (top < down){
    //top
    for (size_t i {left}; i < right; ++i){
      ret.push_back(snail_map[top][i]);
    }
    ++top;
    
    //right
    for (size_t i {top}; i < right; ++i){
    ret.push_back(snail_map[i][right - 1]);
    }
    --right;

    //down 
    for (size_t i {right}; i > left; --i){
      ret.push_back(snail_map[down - 1][i - 1]);
    }
    --down;

    //left
    for (size_t i {down}; i > top; --i){
      ret.push_back(snail_map[i - 1][left]);
    }
    ++left;
  }
  
  return ret;
}