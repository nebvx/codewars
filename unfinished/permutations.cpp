#include <string>
#include <vector>
#include <algorithm>

std::vector<std::string> permutations(std::string s) {
  std::vector<std::string> res = {};
  for (size_t i {0}; i < s.size(); ++i) {
    for (size_t z {0}; z < s.size(); ++z) {
      std::string per;
      per.push_back(s[i]);
      for (size_t j {0}; j < s.size(); ++j) {
        if (i != (j + z) % s.size()) {
          int ind = (j + z) % s.size();
          std::cout << "ind: " << ind << "\n";
          per.push_back(s[ind]);
        } 
      }
      std::cout << "per: " << per << "\n";
      if (std::find(res.begin(), res.end(), per) == res.end() && per.size() == s.size()) {
        res.push_back(per); 
      }
    }
  }
  return res;
}