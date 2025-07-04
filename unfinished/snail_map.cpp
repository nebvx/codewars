#include <vector>

std::vector<int> snail(const std::vector<std::vector<int>> &snail_map) {
  std::vector<int> ret;
  size_t top{0}, right{snail_map[0].size()}, down{right}, left{0};
  for (auto i : snail_map){
    
    ret.push_back(i);
  }
  
  return ret;
}