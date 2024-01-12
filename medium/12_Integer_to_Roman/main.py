class Solution:
    def intToRoman(self, num: int) -> str:
        # num : 0 > num > 4000
        # thousands : 0 1000 2000 3000
        # hundreds : 0 100 200 300 400 500 600 700 800 900
        # tens : 0 10 20 30 40 50 60 70 80 90
        # ones : 0 1 2 3 4 5 6 7 8 9

        thousands = ["", "M", "MM", "MMM"] 
        hundreds = ["", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"]
        tens = ["", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"]
        ones = ["", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"]
        
        roman_numeral = thousands[num // 1000] + hundreds[(num % 1000) // 100] + tens[(num % 100) // 10] + ones[num % 10]
        
        return roman_numeral