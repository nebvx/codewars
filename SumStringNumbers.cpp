#include <string>
#include <algorithm>

std::string sum_strings(const std::string& a, const std::string& b) {
  size_t a_length = a.size();
  size_t b_length = b.size();
  size_t max = std::max(a_length, b_length);
  int number {0}, leftover {0}, dig_a {0}, dig_b {0};
  std::string sum;
  
  for (size_t i {0}; i < max; ++i){
    dig_a = i < a_length ? a[a_length - i - 1] - '0' : 0;
    dig_b = i < b_length ? b[b_length - i - 1] - '0' : 0;
    number = dig_a + dig_b + leftover;
    leftover = number / 10;
    sum.push_back((number % 10) + '0');
  }
  
  if (leftover) sum.push_back(leftover + '0');
  std::reverse(sum.begin(), sum.end());
  return sum;
}