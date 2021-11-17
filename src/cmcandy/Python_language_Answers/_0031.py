from typing import List


class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        # 降序遍历,找到第一个后者>前者的位置x，以此为轴，找到后方<=x且>x-1的值，交换即可，x后边应当变为升序
        length = len(nums)
        index = length - 1
        while index > 0:
            if nums[index] > nums[index - 1]:
                if index == length - 1:
                    nums[index], nums[index - 1] = nums[index - 1], nums[index]
                    return nums

                for i in range(index + 1, length):
                    # 12542 -> 14225
                    if nums[index - 1] >= nums[i]:
                        nums[index - 1], nums[i - 1] = nums[i - 1], nums[index - 1]
                        nums[index:length] = sorted(nums[index:length])
                        return nums

                nums[index - 1], nums[length - 1] = nums[length - 1], nums[index - 1]
                nums[index:length] = sorted(nums[index:length])
                return nums
            index -= 1

        # 这个是转完了，重新从小开始
        return nums.sort()


if __name__ == '__main__':
    s = Solution()
    print(s.nextPermutation([1, 3, 2]))
    print(s.nextPermutation([1, 3, 1]))
