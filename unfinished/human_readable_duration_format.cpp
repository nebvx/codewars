#include <string>

std::string format_duration(int seconds) {
  if (seconds == 0) { return "now"; }
  int year {0}, day {0}, hour {0}, min {0}, sec {0};
  for (int temp {seconds}; temp > 0; ){
    if (temp >= 31536000){
      ++year;
      temp -= 31536000;
    } else if (temp >= 86400) {
      ++day;
      temp -= 86400;
    } else if (temp >= 3600){
      ++hour;
      temp -= 3600;
    } else if (temp >= 60) {
      ++min;
      temp -= 60;
    } else {
      ++sec;
      --temp;
    }
  } 
  
  //int to string
  std::string time = "";
  if (year != 0){
    time += std::to_string(year) + " year";
    if (year > 1) { 
      time += "s"; 
    }
  }
  if (day != 0){
    if (!time.empty()) {
      sec && min && day == 0 ? time += " and " : time += ", ";
    }
    time += std::to_string(day) + " day";
    if (day > 1) { 
      time += "s"; 
    }
  }
  if (hour != 0) {
    if (!time.empty()) {
      sec && min == 0 ? time += " and " : time += ", ";
    }
    time += std::to_string(hour) + " hour";
    if (hour > 1) { 
      time += "s"; 
    }
  }
  if (min != 0) {
    if (!time.empty()) {
      sec == 0 ? time += " and " : time += ", ";
    }
    time += std::to_string(min) + " minute";
    if (min > 1) { 
      time += "s"; 
    }
  }
  if (sec != 0) {
    if (!time.empty()) {
      time += " and ";
    }
    time += std::to_string(sec) + " second";
    if (sec > 1) { 
      time += "s"; 
    }
  }
  return time;
}