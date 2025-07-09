#include <vector>
bool validate_battlefield(std::vector< std::vector<int> > field) {
// Write your magic here ;)
std::vector<std::vector<bool>> visited(10, std::vector<bool>(10, false));
size_t battleship {0}, cruiser {0}, destroyer {2}, sub{0};
//single battleship (size of 4 cells), 2 cruisers (size 3), 3 destroyers (size 2) and 4 submarines (size 1).
for (size_t y {0}; y < 10; ++y){
  for (size_t x {0}; x < 10; ++x){
      bool vertical {false};
      if (field[y][x] == 1){ //found a ship
        //horizontal or vertical
        if (field[y][x + 1] == 1){
          vertical = true;
        } 
        size_t ship_size {0};
        for (size_t i {0}; i < 4; ++i){ // finding ship size 
          ++ship_size
          if ((field[y][x + i] == 0 && vertical) || (field[y + i][x] == 0 && !vertical)){
            break;
          }  
        }
        for (size_t i {0}; i < ship_size; ++i){ //looking for unallowed overlaps
          if (!x == 0) { //left
            //above
            if (!y == 0) { //first line
              if (field[x - 1 + i][y + 1] == 1) { //starts diagnally left 
                std::cout << "overlay above\n";
                return false;
              }
            }
            //beneath
            if (!y == 9){ //last line
              if (field[x - 1 + i][y - 1] == 1) { //starts diagnally left 
                std::cout << "overlay beneath\n";
                return false;
              }
            }
          }
        }
      }
      switch (ship_size) {
      case 1:
        if (sub > 4) { return false; } //only four allowed
        ++sub;
      case 2:
        if (destroyer > 3) { return false; } //only three allowed
        ++destroyer;
      case 3:
        if (cruiser > 2) { return false; } //only two allowed
        ++cruiser;
      case 4:
        if (battleship > 1) { return false; } //only one allowed
        ++battleship;
      }
    } 
  }
  return true;
}
