#include <string>

std::string encode_rail_fence_cipher(const std::string &str, int n) {
  std::string encoded = "", messages = str;
  int count {0};
  
  for (int i {n - 1}; i >= 0; --i) {
    std::string temp = "";
    for (size_t j {0}; j < messages.size(); ++j){
      if (count++ == 0) {
          encoded += messages[j];
      } else {
          temp += messages[j];
      }
      if (count == i + i) { count = 0; }
    }
    messages = temp;
    std::cout << "ended: " << i << ", messages: " << messages << "\n";
  }
  return encoded;
}

std::string decode_rail_fence_cipher(const std::string &str, int n) {
  return "";
}
