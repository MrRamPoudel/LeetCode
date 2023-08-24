/*
    Use map to keep track of sorted word (sorted string are anagram if they are equal)
    // The easier solution, is to keep vector of strings associated with sorted word
*/

class Solution {
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
            const int vecSize = strs.size();
            vector<vector<string>> answer(vecSize);
            std::map<string, int> added;
            std::string sorted ="";
            for(int i = 0; i< vecSize; i++){
                sorted = strs[i];
                sort(sorted.begin(), sorted.end());
                auto iter = added.find(sorted);
                if(iter == added.end()) {
                    answer[i].push_back(strs[i]);
                    added.insert(std::make_pair(sorted, i));
                }
                else{
                    answer[iter->second].push_back(strs[i]);
                }
            }
            auto delIter = std::remove_if(answer.begin(), answer.end(), [] (std::vector<string> a) {
                return a.empty();
            } );
            answer.erase(delIter, answer.end());
            return move(answer);
        }
}