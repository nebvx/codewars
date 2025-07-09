#include <vector>
bool validate_battlefield(std::vector< std::vector<int> > field) {
  // Write your magic here ;)
  std::vector<std::vector<bool>> visited(10, std::vector<bool>(10, false));
  size_t battleship {0}, cruiser {0}, destroyer {2}, sub{0};
  //single battleship (size of 4 cells), 2 cruisers (size 3), 3 destroyers (size 2) and 4 submarines (size 1).
  for (size_t y {0}; y < 10; ++y){
    for (size_t x {0}; x < 10; ++x){
      if (field[y][x] == 1){ //ship found
        size_t ship_size {0};
        for (size_t i {0}; i < 4; ++i){ //ship size loop
          bool down {true}, right {true};
          if (field[y + i][x] && down) { //down 
            right = false;
            if right { return false; } //overlap
            ++ship_size;
          } else if (field[y][x + i] && right) { // right
            down = false;
            if (down) { return false; } //overlap
            ++ship_size;
          } else { //0 in both directions
            break;
          }
        }
        //ship_size gets saved
        switch
      }
      
    }
  }
  return true;
}