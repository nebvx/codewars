#include <string>

std::string format_duration(int seconds) {
  if (seconds == 0) { return "now"; }
  
  int hours {second}, temp {second};
  for (size_t h {seconds}; h > 60; h/60){
    ++hours;
  }
  
  int minutes = seconds
  for (size_t h {seconds}; h < 60; h/60){
    ++hours;
  } 
  
  return "now";
}