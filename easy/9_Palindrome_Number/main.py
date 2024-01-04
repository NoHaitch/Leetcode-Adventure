class Solution:
    def isPalindrome(self, x: int) -> bool:
        num_str = str(x)
        return num_str == num_str[::-1]