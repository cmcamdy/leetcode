from typing import List


class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        length = len(nums)
        res = nums[0] + nums[1] + nums[length - 1]
        for index in range(length):
            left = index + 1
            right = length - 1
            while left < right:
                if abs(nums[index] + nums[left] + nums[right] -
                       target) < abs(res - target):
                    res = nums[index] + nums[left] + nums[right]

                if nums[index] + nums[left] + nums[right] - target > 0:
                    right -= 1
                elif nums[index] + nums[left] + nums[right] - target < 0:
                    left += 1
                else:
                    return target
        return res
