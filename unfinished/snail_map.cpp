#include <vector>

std::vector<int> snail(const std::vector<std::vector<int>> &snail_map) {
  std::vector<int> ret;
  size_t top{0}, right{snail_map[0].size()}, down{right}, left{0};
  while (top < down){
    //top
    for (size_t i {0}; i < right; ++i){
      ret.push_back(snail_map[top][i]);
    }
    ++top;
    //right
    for (size_t i {0}; i < down - 1; ++i){
      ret.push_back(snail_map[top + i][right]);
    }
    
    //down 
    for (size_t i {down}; i > 0; --i){
      ret.push_back(snail_map[down][i]);
    }
 
    //left
    for (size_t i {0}; i < ; ++i){
      ret.push_back(snail_map[top + i][right]);
    }
  }
  
  return ret;
}