class solution:
        def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
            numDict = {}
            for i in range(len(nums)):
                if nums[i] in numDict and abs(numDict[nums[i]] - i) <=k:
                    return True
                numDict[nums[i]] = i
            return False
