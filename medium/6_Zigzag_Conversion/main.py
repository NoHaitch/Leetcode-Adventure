class Solution:
    def convert(self, s: str, numRows: int) -> str:
        length = len(s)

        if length <= numRows or numRows == 1:
            return s

        rows = [[] for _ in range(numRows)]
        
        i = 0
        step = -1
        for char in s:
            rows[i].append(char)
            if i == 0:
                step = 1
            elif i == numRows - 1:
                step = -1
            i += step

        for i in range(numRows):
            rows[i] = ''.join(rows[i])
        return ''.join(rows)         