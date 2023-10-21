class Solution {
    public int[] searchRange(int[] nums, int target) {
        int first = -1;
        int last = -1;
        for(int i = 0; i <nums.length; ++i) {
            if(nums[i] == target && first == -1) {
                first = i;
                continue;
            }
            if(nums[i] == target && first != -1) {
                last = i;
            }
        }
        if(last == -1) {
            last = first;
        }
        int [] ans = {first, last};
        return ans;
    }
}