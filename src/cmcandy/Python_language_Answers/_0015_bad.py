from typing import List


# 超时
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        length = len(nums)
        # res = set()
        res = []
        for l in range(0, length - 2):
            if not (l > 0 and nums[l - 1] == nums[l]):
                for m in range(l + 1, length - 1):
                    if not (m > l + 1 and nums[m - 1] == nums[m]):
                        # for r in range(m+1,length):
                        left = m + 1
                        right = length - 1
                        while left <= right:
                            r = (left + right) // 2
                            if nums[l] + nums[m] + nums[r] == 0:
                                # res.add((nums[l], nums[m], nums[r]))
                                res.append([nums[l], nums[m], nums[r]])
                                # left = right +1
                                break
                            elif nums[l] + nums[m] + nums[r] > 0:
                                right = r - 1
                            elif nums[l] + nums[m] + nums[r] < 0:
                                left = r + 1

        return res
