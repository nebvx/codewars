#include <vector>
bool validate_battlefield(std::vector< std::vector<int> > field) {
  std::vector<std::vector<bool>> visited(10, std::vector<bool>(10, false));
  size_t battleship {0}, cruiser {0}, destroyer {0}, sub{0};
  //single battleship (size of 4 cells), 2 cruisers (size 3), 3 destroyers (size 2) and 4 submarines (size 1).
  for (size_t y {0}; y < 10; ++y){
    for (size_t x {0}; x < 10; ++x){
      bool vertical {false};
      if (field[y][x] == 1 && visited[y][x] == 0){ //found new ship
        if (field[y][x + 1] == 1){ //horizontal or vertical
          vertical = true;
        }
        
        size_t ship_size {0};
        for (size_t i {0}; i < 4; ++i){ // finding ship size 
          if (ship_size > 4){
            return false;
          }
          if ((field[y][x + i] == 0 && vertical) || (field[y + i][x] == 0 && !vertical)){
            break;
          }
          ++ship_size;
          vertical ? visited[y][x + i] = 1 : visited[y + i][x] = 1; //mapping found ship to visited
        }
        
        for (size_t i {0}; i < ship_size; ++i){ //looking for unallowed overlaps
          if (x + i != 0 && vertical) { //left
            //beneath
            if (y != 9){ //last line
              if (field[y + 1][x - 1 + i] == 1) { //starts diagnally down left 
                return false;
              }
            }
          } else if (y + i != 0 && !vertical) {
            if(x != 9) {
              if (field[y - 1 + i][x + 1] == 1) { //starts diagnally up right 
                return false;
              }
            }
          }
        }
          
        switch (ship_size) {
        case 1: //only four allowed
          if (++sub > 4) { 
            return false; 
          } 
          break;
        case 2: //only three allowed
          if (++destroyer > 3) {
            return false;
          } 
          break;
        case 3: //only two allowed
          if (++cruiser > 2) { 
            return false; 
          }
          break;
        case 4: //only one allowed
          if (++battleship > 1) {  
            return false; 
          } 
          break;
        }
      } 
    }
  }
  if (sub != 4 || destroyer != 3 || cruiser != 2 || battleship != 1) {
    return false; //ships are missing
  }
  return true;
}