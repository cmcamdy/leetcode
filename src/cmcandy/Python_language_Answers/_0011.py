from typing import List


class Solution:
    def maxArea(self, height: List[int]) -> int:
        length = len(height)
        right = length - 1
        left = 0

        res = (right - left) * min(height[left], height[right])

        while right > left:
            if height[left] < height[right]:
                left += 1
            else:
                right -= 1
            res = max(res, (right - left) * min(height[left], height[right]))
        return res
