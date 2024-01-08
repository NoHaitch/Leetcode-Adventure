class Solution:
    def reverse(self, x: int) -> int:
        sign = [1,-1][x < 0]
        ans = sign * int(str(abs(x))[::-1])
        
        if -(2**31)-1 < ans < 2**31:
            return ans
        else:
            return 0