from typing import List


class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        length = len(nums)
        # 偷了个懒用set去重
        res = set()
        # res = []
        for l in range(0, length - 2):
            if not (l > 0 and nums[l - 1] == nums[l]):
                left = l + 1
                right = length - 1
                # 双指针左右逼近
                while left < right:
                    if nums[l] + nums[left] + nums[right] > 0:
                        right -= 1
                    elif nums[l] + nums[left] + nums[right] < 0:
                        left += 1
                    else:
                        res.add((nums[l], nums[left], nums[right]))
                        left += 1

        return list(res)
