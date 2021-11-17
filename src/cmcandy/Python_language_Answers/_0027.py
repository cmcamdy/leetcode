from typing import List
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        cur = 0
        for index in range(len(nums)):
            if nums[index] != val:
                nums[cur] = nums[index]
                cur += 1
        return cur