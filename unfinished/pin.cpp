#include <string>
#include <vector>

std::vector<std::string> get_pins(std::string observed) {
    std::vector<std::vector<std::string>> res;
    int num {std::stoi(observed)};
    //getting all possible digits
    while (num > 0) {
        int std::vector<std::string> curr;
        int dig = num % 10;
        num /= 10;
        curr.push_back(std::to_string(dig));
        if (dig != 1 && dig != 4 && dig != 7 && dig != 0) curr.push_back(std::to_string(dig - 1));
        if (dig != 9 && dig != 6 && dig != 3 && dig != 0) curr.push_back(std::to_string(dig + 1));

        if (dig > 3) { curr.push_back(std::to_string(dig - 3)); }
        if (dig < 7) { curr.push_back(std::to_string(dig + 3)); }

        //expection; mostly with 0
        if (dig == 8) { curr.push_back("0"); }

        //adding current vector to result
        res.push_back(curr);
    }

    //combining all digits
    for ()

    std::sort(res.begin(), res.end());
    return res;
}