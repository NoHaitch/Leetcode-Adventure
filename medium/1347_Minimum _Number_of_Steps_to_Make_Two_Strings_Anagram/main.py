class Solution:
    def minSteps(self, s: str, t: str) -> int:
        counter = 0

        for char in set(s):
            diff = s.count(char) - t.count(char)
            counter += diff if diff > 0 else 0
            
        return counter