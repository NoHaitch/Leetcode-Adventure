from typing import List

class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        if n == 0:
            return

        if m == 0:
            for i in range(n):
                nums1[i] = nums2[i]
            return

        curr = m + n - 1
        idx1 = m - 1
        idx2 = n - 1
        
        while idx2 >= 0:
            if idx1 >= 0 and nums1[idx1] > nums2[idx2]:
                nums1[curr] = nums1[idx1]
                idx1 -= 1
            else:
                nums1[curr] = nums2[idx2]
                idx2 -= 1
            curr -= 1