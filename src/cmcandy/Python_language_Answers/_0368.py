from typing import List


class Solution:
    def largestDivisibleSubset(self, nums: List[int]) -> List[int]:
        length = len(nums)
        if length == 1:
            return nums
        if length == 2:
            if nums[0] % nums[1] == 0 or nums[1] % nums[0] == 0:
                return nums
            else:
                return [nums[0]]
        dp = [1 for index in range(length)]

        max_ind, max_len = 0, 0
        nums.sort()
        for i in range(1, length):
            # 找到以当前值（nums[i]）为最大值的集合
            max_i = 0
            j = i - 1
            while (j >= 0):
                if nums[i] % nums[j] == 0:
                    if dp[j] >= max_i:
                        max_i = dp[j]
                j -= 1

            dp[i] += max_i

            if dp[i] > max_len:
                max_ind = i
                max_len = dp[i]

        # 找到序列
        res = [1 for index in range(max_len)]
        res[0] = nums[max_ind]
        index = max_ind - 1
        count = 1
        while (index >= 0):
            if nums[max_ind] % nums[index] == 0 and dp[index] + 1 == max_len:
                res[count] = nums[index]
                count += 1
                max_ind = index
                max_len -= 1
            index -= 1

        return res


if __name__ == '__main__':
    s = Solution()

    print(s.largestDivisibleSubset([3, 4, 16, 8]))