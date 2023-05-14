class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0:
            return False
        #compare the reverse
        return str(x) == str(x)[::-1]