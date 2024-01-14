from typing import List

class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        ans = []

        if numRows > 0:
            ans.append([1])

        for i in range(1, numRows):
            prev = ans[i-1]
            cur = [1]

            for j in range(1, i):
                cur.append(prev[j-1] + prev[j])

            cur.append(1)
            ans.append(cur)

        return ans