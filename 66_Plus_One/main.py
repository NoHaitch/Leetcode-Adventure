from typing import List

class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        digits_str = [str(i) for i in digits]
        num = str(int("".join(digits_str)) + 1)
        return [int(i) for i in num]