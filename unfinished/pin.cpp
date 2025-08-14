#include <string>
#include <vector>

std::vector<std::string> get_pins(std::string observed) {
    std::vector<std::vector<std::string>> possible_digits;
    std::vector<std::string> res;
      
    int num {std::stoi(observed)};
    //getting all possible digits
    for (size_t i {0}; i < observed.size(); ++i) {
        int dig = num % 10;
        num /= 10;
      
        std::cout << dig;
        std::vector<std::string> curr;
        curr.push_back(std::to_string(dig));
        if (dig != 1 && dig != 4 && dig != 7 && dig != 0) curr.push_back(std::to_string(dig - 1));
        if (dig != 9 && dig != 6 && dig != 3 && dig != 0) curr.push_back(std::to_string(dig + 1));
        if (dig > 3) { curr.push_back(std::to_string(dig - 3)); }
        if (dig < 7) { curr.push_back(std::to_string(dig + 3)); }
        if (dig == 8) { curr.push_back("0"); }

        possible_digits.push_back(curr);
    }

    //combining all digits
    for (size_t i {0}; i < possible_digits.size(); ++i) {
        for (size_t j {0}; j < possible_digits[i].size(); ++j) {
            res.push_back(possible_digits[i][j]);
        }
    }

    std::sort(res.begin(), res.end());
    return res;
}
