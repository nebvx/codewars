#include <string>

std::string format_duration(int seconds) {
  if (seconds == 0) { return "now"; }
  int hours {0}, min {0}, sec {0};
  int temp {second};
  for (; temp > 3600; temp/60){
    ++hours;
  }
  for (; temp > 60; h/60){
    ++min;
  } 
  for (; temp > 0; --h){
    ++sec;
  } 
  
  //int to string
  string ret = "";
  if (hours != 0) {
    ret += std::to_string(hours) + " hour";
    if (hours > 1) { ret += "s"; }
  }
  if 
  return ;
}