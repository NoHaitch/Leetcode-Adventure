class Solution:
    def rob(self, nums):
        n = len(nums)

        robbed, notRobbed = [0, 0], [0, 0]
        notRobbed[0] = nums[0]

        for i in range(1, n):
            robbed[i % 2] = max(robbed[(i - 1) % 2], notRobbed[(i - 1) % 2])
            notRobbed[i % 2] = robbed[(i - 1) % 2] + nums[i]

        return max(robbed[(n - 1) % 2], notRobbed[(n - 1) % 2])
