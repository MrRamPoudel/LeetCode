class Solution:
    # the idea: get last digit by getting the remainder, multiply result by 10 each iteration, divide num by 10
    def reverse(self, x: int) -> int:
        num = abs(x)
        res = 0
        while num>0:
            res = (res* 10) + (num % 10)
            num //=10
        if x < 0:
            res = res * -1
            return 0 if res <= pow(-2, 31) else res
        return 0 if res >= (pow(2,31) + 1) else res