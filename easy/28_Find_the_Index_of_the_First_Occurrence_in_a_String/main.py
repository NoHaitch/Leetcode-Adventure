class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        needle_len = len(needle)
        for i in range(len(haystack)):
            check_str = haystack[i:needle_len+i]
            if  check_str == needle:
                return i

        return -1
    
    # Built in method
    def strStr1(self, haystack: str, needle: str) -> int:
        return haystack.find(needle)