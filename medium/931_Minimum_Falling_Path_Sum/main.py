from typing import List

class Solution:
    def minFallingPathSum(self, matrix: List[List[int]]) -> int:
        n = len(matrix)
        dp = [[0] * n for _ in range(n)]

        for j in range(n):
            dp[0][j] = matrix[0][j]

        for i in range(1, n):
            for j in range(n):
                left = right = float('inf')
                mid = matrix[i][j] + dp[i - 1][j]

                if j - 1 >= 0:
                    left = matrix[i][j] + dp[i - 1][j - 1]
                if j + 1 < n:
                    right = matrix[i][j] + dp[i - 1][j + 1]

                dp[i][j] = min(mid, left, right)

        return min(dp[n-1])