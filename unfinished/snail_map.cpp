#include <vector>

std::vector<int> snail(const std::vector<std::vector<int>> &snail_map) {
  std::vector<int> ret;
  if (snail_map.empty() || snail_map[0].empty()) {
    return ret;
  }

  size_t top{0}, right{snail_map[0].size()}, down{right}, left{0};
  while (top < down){
    //top
    for (size_t i {0}; i < right; ++i){
      ret.push_back(snail_map[top][i]);
    }
    ++top;
    //right
    
    for (size_t i {top}; i < right; ++i){
      std::cout << "i: " << i << ", right: " << right << "\n";
      ret.push_back(snail_map[i][right - 1]);
    }
    --right;
    
    //down 
    for (size_t i {right}; i > 0; --i){
      std::cout << "i: " << i << ", right: " << right << "\n";
      ret.push_back(snail_map[down - 1][i - 1]);
    }
    --down;
    
    
    //left
    for (size_t i {0}; i < down - top; ++i){
      ret.push_back(snail_map[down - i][left]);
    }
    ++left;
  }
  
  return ret;
}