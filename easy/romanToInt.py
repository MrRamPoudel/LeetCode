'''The idea here is when the number character that is smaller appears
before bigger, we subtract that number else we add'''

class Solution:
    def romanToInt(self, s: str) -> int:
        symbol = { {'I', 1}, {'V', 5}, {'X', 10}, {'L',50}, {'C', 100}, {'D', 500}, {'M', 1000}}
        ans = s[len(s)-1]
        for i in range(len(s) -1):
            if symbol[s[i]] < symbol[s[i +1]]:
                ans -= symbol[s[i]]
            else:
                ans += symbol[s[i]]
        return ans