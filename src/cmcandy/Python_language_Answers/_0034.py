from typing import List


class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        self.length = len(nums)
        index = self.Binary(nums, 0, self.length - 1, target)
        if index == -1:
            return [-1, -1]
        return [
            self.Binary_bound_left(nums, 0, index, target),
            self.Binary_bound_right(nums, index, self.length - 1, target)
        ]

    def Binary(self, nums, left, right, target):
        while left <= right:
            mid = (left + right) // 2
            if nums[mid] == target:
                return mid
            elif nums[mid] > target:
                right = mid - 1
            elif nums[mid] < target:
                left = mid + 1
        return -1

    # 还是老老实实重写俩bin吧
    def Binary_bound_left(self, nums, left, right, target):
        if nums[left] == target:
            return left
        while left <= right:
            mid = (left + right) // 2
            if nums[mid] == target:
                if nums[mid - 1] != target:
                    return mid
                else:
                    right = mid - 1
            elif nums[mid] < target:
                left = mid + 1
        return -1

    def Binary_bound_right(self, nums, left, right, target):
        # 已经是边界了
        if nums[right] == target:
            return right
        while left <= right:
            mid = (left + right) // 2
            if nums[mid] == target:
                if nums[mid + 1] != target:
                    return mid
                else:
                    left = mid + 1
            elif nums[mid] > target:
                right = mid - 1
        return -1


if __name__ == '__main__':
    pass
    s = Solution()
    print(s.searchRange([2,2], 2))
    print(s.searchRange([5, 7, 7, 8, 8, 10], 8))
