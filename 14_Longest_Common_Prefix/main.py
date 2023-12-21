from typing import List

class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        n = len(strs)
        if(n == 0):
            return ""
        elif(n == 1):
            return strs[0]
        ans = ""
        x = min(strs, key=len)
        for i, char in enumerate(x):
            for word in strs:
                if(word != x):
                    if(word[i] != char):
                        return ans
            ans += char
        return ans
