/*
    The idea here is to calculate the prefix and postfix product
    for each indices
*/

class Solution {
    public:
    vector<int> productExceptSelf(vector<int>& nums){
        int cur =1;
        const int n = nums.size();
        vector<int> ans(n);
        fill(ans.begin(), ans.end(), 1);
        //The first element has no prefix as such it remains the same(mul by 1)
        for(int i =0; i<n; ++i){
            ans[i] *=cur;
            cur *= nums[i];
        }
        cur =1;
        //Last element has no post fix, remains the same
        for(int i = n-1; i>=0; --i){
            ans[i] *= cur;
            cur *= nums[i];
        }
        return move(ans)
    }
}