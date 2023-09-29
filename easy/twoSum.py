class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        ans = []
        i = 0
        for i, j in zip(range(0, len(nums)), range(i+1, len(nums))):
            if nums[i] + nums[j] == target:
                ans.append(i)
                ans.append(j)
                return ans
        return ans
