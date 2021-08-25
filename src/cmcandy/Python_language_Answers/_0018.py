from typing import List


class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        nums.sort()
        length = len(nums)
        # 偷了个懒用set去重
        res = set()
        # res = []
        for fir in range(0, length - 3):
            if not (fir > 0 and nums[fir - 1] == nums[fir]):
                for sec in range(fir + 1, length - 2):
                    if not (sec > fir + 1 and nums[sec - 1] == nums[sec]):
                        left = sec + 1
                        right = length - 1
                        # 双指针左右逼近
                        while left < right:
                            if nums[fir] + nums[sec] + nums[left] + nums[
                                    right] > target:
                                right -= 1
                            elif nums[fir] + nums[sec] + nums[left] + nums[
                                    right] < target:
                                left += 1
                            else:
                                res.add((nums[fir], nums[sec], nums[left],
                                         nums[right]))
                                left += 1

        return list(res)