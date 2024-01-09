class Solution:
    def myAtoi(self, s: str) -> int:
        INT_MAX = 2 ** 31 - 1
        INT_MIN = -2 ** 31
        
        s = s.strip()
        sign = 1
        i = 0
        num = 0
        
        if not s:
            return num
        
        if s[0] == '-':
            sign = -1
            i += 1
        elif s[0] == '+':
            i += 1
        
        while i < len(s) and s[i].isdigit():
            curr_digit = ord(s[i]) - ord('0')
            
            if num > INT_MAX // 10 or (num == INT_MAX // 10 and curr_digit > 7):
                return INT_MAX if sign == 1 else INT_MIN
            
            num = num * 10 + curr_digit
            i += 1
        
        num = sign * num
        return num    