/*
Consider the item at ith position + i+m items
*/
#include <vector>
using namespace std;
class Solution{
    public:
    int birthday(vector<int> s, int d, int m) {
    int ways = 0;
    int n = s.size();
    int sum = 0;
    for (int i = 0; i+m <=n; ++i) {
        for (int j = i; j<i+m; ++j) {
            sum += s[j];
        }
        if(sum == d) {
            ++ways;
        }
        sum = 0;
    }
    return ways;
}
};