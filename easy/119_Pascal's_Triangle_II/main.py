from typing import List

class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        ans = [] 

        for i in range(rowIndex + 1):
            currRow = [] 

            for j in range(i + 1):
                if j == 0 or j == i:
                    currRow.append(1)
                else:
                    currRow.append(ans[i-1][j-1] + ans[i-1][j])

            ans.append(currRow)
        
        return ans[rowIndex]