from typing import List


class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:

        # 二分法
        left, right = 0, len(nums) - 1
        if nums[left] >= target:
            return left
        elif nums[right] < target:
            return right + 1
        elif nums[right] == target:
            return right
        while left < right:
            mid = (left + right) // 2
            if nums[mid] > target:
                if nums[mid - 1] < target:
                    return mid
                elif nums[mid - 1] == target:
                    return mid - 1
                else:
                    right = mid - 1
            elif nums[mid] == target:
                return mid
            elif nums[mid] < target:
                if nums[mid + 1] >= target:
                    return mid + 1
                else:
                    left = mid + 1
        return -1



