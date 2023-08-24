#include <string>
#include <vector>
#include <utility>
#include <iostream>
/*
    Simply divide by each of the possible symbol (including the special case)
*/
class Solution {
public:
    static std::string intToRoman(int num) {
        std::vector<std::pair<std::string, int>> table = {
            {"I", 1}, { "IV", 4}, {"V", 5}, {"IX", 9}, {"X", 10},
            {"XL", 40}, {"L", 50}, {"XC", 90}, {"C", 100}, {"CD", 400},
            {"D", 500}, {"CM", 900}, {"M", 1000}
        };
        int times =0;
        std::string res ="";
        for(auto iter = table.rbegin(); iter != table.rend(); ++iter){
            times = num/ iter->second;
            if(times) {
                while(times) {
                    res += iter->first;
                    num %= iter->second;
                    --times;
                }
            }
        }
        return move(res);
    }
};

int main() {
    std::cout << Solution::intToRoman(43) <<'\n';
    return 0;
}
