#include <vector>
bool validate_battlefield(std::vector< std::vector<int> > field) {
  std::vector<std::vector<bool>> visited(10, std::vector<bool>(10, false));
  for (size_t y {0}; y < 10; ++y){
    for (size_t x {0}; x < 10; ++x){
      if (field[y][x] == 1){ //ship found
        for (size_t i {0}; i < 4; ++i){
          if (field[y + i][x]) { //down 
            
          } else if (field[y][x + i]) { // right
            
          }
        }
      }
    }
  }
  return true;
}