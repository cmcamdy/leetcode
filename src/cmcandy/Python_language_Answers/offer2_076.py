# from typing import List

# class Solution:
#     def findKthLargest(self, nums: List[int], k: int) -> int:
#         # 撸一个大根堆
#         self.nums = nums
#         self.length = len(nums)
#         self.k = k
#         # 构造一个堆
#         self.buildPile()
#         for index in range(k - 1):
#             # 顶点最大值弹出
#             self.nums[self.length - 1], self.nums[0] = self.nums[0], self.nums[self.length - 1]
#             self.length -= 1
#             self.modifyTree(0, self.length)
#         return self.nums[0]

#     def buildPile(self):
#         index = self.length - 1
#         tmp = 0
#         if index % 2 == 1:
#             if self.nums[index] > self.nums[index // 2]:
#                 # 交换
#                 self.nums[index], self.nums[index // 2] = self.nums[index // 2], self.nums[index]
#             index -= 1

#         while index > 0:
#             # 比较得两自问题的较大者
#             if self.nums[index] > self.nums[index - 1]:
#                 tmp = index
#             else:
#                 tmp = index - 1
#             # 如果底部较大，上浮
#             if self.nums[tmp] > self.nums[index // 2 - 1]:
#                 self.nums[tmp], self.nums[index // 2 - 1] = self.nums[index // 2 - 1], self.nums[tmp]
#                 self.modifyTree(tmp)
#             index -= 2

#     def modifyTree(self, root=0, length=None):
#         if length is None:
#             length = self.length
#         # 假设下方子树都已满足大根堆，然后只有顶端不满足
#         if root * 2 + 1 >= length:
#             # 下方没有子节点了，直接返回
#             return
#         elif root * 2 + 2 >= length:
#             # 下方右侧没有
#             if self.nums[root * 2 + 1] > self.nums[root]:
#                 self.nums[root], self.nums[root * 2 + 1] = self.nums[root * 2 + 1], self.nums[root]
#         else:
#             if self.nums[root * 2 + 1] > self.nums[root * 2 + 2]:
#                 tmp = root * 2 + 1
#             else:
#                 tmp = root * 2 + 2
#             if self.nums[tmp] > self.nums[root]:
#                 self.nums[root], self.nums[tmp] = self.nums[tmp], self.nums[root]
#                 self.modifyTree(tmp, length)
#         # 调整完毕，返回
#         return

# if __name__ == '__main__':
#     s = Solution()
#     # s.nums = [3,2,1,5,6,4]
#     # s.findKthLargest([3, 2, 1, 5, 6, 4], 3)
#     s.findKthLargest([2, 1], 2)
#     # s.buildPile()
#     pass

import sys
from typing import List


class Solution:
    def findKthLargest(self, nums: List[int], k: int, length: int) -> int:
        # 撸一个大根堆
        self.nums = nums
        self.length = length
        self.k = k
        # 构造一个堆
        self.buildPile()
        for index in range(k - 1):
            # 顶点最大值弹出
            self.nums[self.length -
                      1], self.nums[0] = self.nums[0], self.nums[self.length -
                                                                 1]
            self.length -= 1
            self.modifyTree(0, self.length)
        return self.nums[0]

    def buildPile(self):
        index = self.length - 1
        tmp = 0
        if index % 2 == 1:
            if self.nums[index] > self.nums[index // 2]:
                # 交换
                self.nums[index], self.nums[index //
                                            2] = self.nums[index //
                                                           2], self.nums[index]
            index -= 1

        while index > 0:
            # 比较得两自问题的较大者
            if self.nums[index] > self.nums[index - 1]:
                tmp = index
            else:
                tmp = index - 1
            # 如果底部较大，上浮
            if self.nums[tmp] > self.nums[index // 2 - 1]:
                self.nums[tmp], self.nums[index // 2 -
                                          1] = self.nums[index // 2 -
                                                         1], self.nums[tmp]
                self.modifyTree(tmp)
            index -= 2

    def modifyTree(self, root=0, length=None):
        if length is None:
            length = self.length
        # 假设下方子树都已满足大根堆，然后只有顶端不满足
        if root * 2 + 1 >= length:
            # 下方没有子节点了，直接返回
            return
        elif root * 2 + 2 >= length:
            # 下方右侧没有
            if self.nums[root * 2 + 1] > self.nums[root]:
                self.nums[root], self.nums[root * 2 +
                                           1] = self.nums[root * 2 +
                                                          1], self.nums[root]
        else:
            if self.nums[root * 2 + 1] > self.nums[root * 2 + 2]:
                tmp = root * 2 + 1
            else:
                tmp = root * 2 + 2
            if self.nums[tmp] > self.nums[root]:
                self.nums[root], self.nums[tmp] = self.nums[tmp], self.nums[
                    root]
                self.modifyTree(tmp, length)
        # 调整完毕，返回
        return


s = Solution()


# for line in sys.stdin:
#     # a = list(map(int, line.split()))
#     a = line.split()
#     a[0], a[1] = int(a[0]), int(a[1])
#     # b = list(map(int, sys.stdin.readline().split()))
#     b = sys.stdin.readline().split()
#     for index in range(a[0]):
#         b[index] = int(b[index])
#     print(s.findKthLargest(b, a[1], a[0]))
for line in sys.stdin:
    a = list(map(int, line.rstrip().split()))
    b = list(map(int, sys.stdin.readline().rstrip().split()))
    # print(s.findKthLargest(b, a[1], a[0]))
    b.sort()
    print(b[a[0]])
tmp = 0
for line in sys.stdin:
    if tmp == 0:
        a = list(map(int, line.split()))
        tmp = 1
    else:
        b = list(map(int, line.split()))
        print(s.findKthLargest(b, a[1], a[0]))
        tmp = 0