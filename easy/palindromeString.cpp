/*
    Move the pointers if they are not alphanumeric
    return false if they are not equal
*/
class Solution {
public:
    bool isPalindrome(string s) {
        if(s.empty() || s== " ")
            return true;
        int start = 0;
        int end = s.length() -1;

        while (start <= end){
            if(!isalnum(s[start])){
                ++start;
                continue;
            }
            if(!isalnum(s[end])) {
                --end;
                continue;
            }
            if (tolower(s[start]) != tolower(s[end]))
                return false;
            ++start;
            --end;
        }
        return true;
    }
};