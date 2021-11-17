from typing import List



class Solution:
    def search(self, nums: List[int], target: int) -> int:
        left = 0
        right = len(nums) - 1
        if right == left:
            return 0 if nums[0] == target else -1
        if nums[left] < nums[right]:
            # 这里就是没有旋转，直接用二分就行
            return self.Binary(nums, left, right, target)

        jud = 1 if nums[0] <= target else 0

        while left <= right:
            mid = (left + right) // 2
            if nums[mid] == target:
                return mid
            elif nums[mid] < target:
                #这里=也可以，应该是测试样例没触碰到这里的边界 if jud == 1 and nums[mid] < nums[0]:
                if jud == 1 and nums[mid] <= nums[0]:
                    right = mid - 1
                else:
                    left = mid + 1
            elif nums[mid] > target:
                if jud == 0 and nums[mid] >= nums[0]:
                    left = mid + 1
                else:
                    right = mid - 1

            if nums[left] <= nums[right]:
                return self.Binary(nums, left, right, target)
        return -1

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

if __name__ == '__main__':
    pass
    s = Solution()
    # print(s.search([4, 5, 6, 7, 0, 1, 2], 0))
    print(s.search([3, 1], 1))
    print(s.search([4, 5, 6, 7, 8, 1, 2, 3], 8))
    print(s.search([5, 1, 3], 3))
    print(s.search([5, 1, 2, 3, 4], 1))
    print(s.search([3, 5, 1], 3))
