from typing import List

class Solution:
    # Way 1: Brute Force, O(n^2)
    def twoSum1(self, nums: List[int], target: int) -> List[int]:
        for i in range(len(nums)):
            for j in range(i+1, len(nums)):
                if(nums[i] + nums[j] == target):
                    return [i, j]

    # Way 2: Hash Map, O(n)
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        seen : map = {}
        for i in range(len(nums)):
            diff = target - nums[i]
            if(nums[i] in seen):
                return [seen[nums[i]], i]
            else:
                seen[diff] = i