class Solution:
    #Check if the number is in hashed set
    def containsDuplicate(self, nums: List[int]) -> bool:
        hashed = set()
        for num in nums:
            if num in hashed:
                return True
            hashed.add(num)   
        return False      
