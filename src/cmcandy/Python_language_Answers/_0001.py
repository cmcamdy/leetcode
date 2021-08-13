
from typing import List
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        map = {}
        for index in range(len(nums)):
            if map.get(target-nums[index]) is None:
                map[nums[index]] = index
            else :
                return  [map[target-nums[index]],index]



so = Solution()
print(so.twoSum([2,7,11,5],9))

