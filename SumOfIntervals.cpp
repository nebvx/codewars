#include <vector>
#include <utility> 

int sum_intervals(std::vector<std::pair<int, int>> intervals) {
  std::vector<std::pair<int, int>> sorted = intervals;

  std::sort(sorted.begin(), sorted.end(), [](std::pair<int, int> a, std::pair<int, int> b) {
    if (a.first != b.first){
      return a.first < b.first;
    } else {
      return a.second < b.second;
    }
  });
  
  std::pair<int, int> temp_int;
  int count {0};
  int last_count {0};
  bool first {true};
  for (auto i : sorted){
    if (first) {
      temp_int = i;
    }

    if (std::get<0>(i) < temp_int.second){ //mergeable
      if (std::get<1>(i) > temp_int.second){ //bigger max
        temp_int.second = std::get<1>(i);
        last_count = 0;
      }
    } else { //not mergeable
      count += last_count;
      last_count = 0;
      temp_int = i;
    }
    
    last_count = temp_int.second - temp_int.first;
    first = false;
  }
  
  return count + last_count;
}