#include <string>
#include <vector>

std::vector<std::string> get_pins(std::string observed) {
    std::vector<std::string> res;
    int num {std::stoi(observed)};
    while (num > 0) {
        int dig = num % 10;
        num /= 10;
        res.push_back(std::to_string(dig));
        if (dig != 1 && dig != 4 && dig != 7 && dig != 0) res.push_back(std::to_string(dig - 1));
        if (dig != 9 && dig != 6 && dig != 3 && dig != 0) res.push_back(std::to_string(dig + 1));

        if (dig > 3) { res.push_back(std::to_string(dig - 3)); }
        if (dig < 7) { res.push_back(std::to_string(dig + 3)); } 
        
        //expection; mostly with 0
        if (dig == 8) { res.push_back("0"); }
    }

    std::sort(res.begin(), res.end());
    return res;
}