from typing import List
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        length = len(nums)
        cur = 0
        map = {}
        for index in range(length):
            if map.get(nums[index]) is None:
                map[nums[index]] = 1
                nums[cur] = nums[index]
                cur += 1
        return cur             
            
