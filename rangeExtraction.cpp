#include <string>
#include <vector>

std::string range_extraction(std::vector<int> args) {
  std::string result;
  int num {0}, start {0}, count{0};
  for (size_t i {0}; i < args.size(); ) {
    num = args[i++];
    if (args[i] == num + 1){
      if (!count){start = num;} 
      ++count;
    } else {
      if (result.size() != 0) { result += ","; };
      if (count > 1){
        result += std::to_string(start) + "-" + std::to_string(num);
      } else {
        if (count == 1) { result += std::to_string(num - 1) + ","; }
        result += std::to_string(num);
      }
      count = 0;
    }
  }
  return result;
}