class Solution:
    def isAnagram(self, s:str, t:str) -> bool:
        #When we sort anagram, they should be identical
        return (sorted(s) == sorted(t))