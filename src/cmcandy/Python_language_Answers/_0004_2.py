from typing import List


# 寻找第K小数法
class Solution:
    def findMedianSortedArrays(self, nums1: List[int],
                               nums2: List[int]) -> float:
        length1, length2 = len(nums1), len(nums2)

        def getKthnum(k=0, i1=0, i2=0):
            # 有一边为0个元素
            # 但这里应该考虑的是新数组的长度,i1代表数组在nums1的左侧边界
            if length1 == i1:
                return nums2[k - 1 + i2]
            elif length2 == i2:
                return nums1[k - 1 + i1]
            elif k == 1:
                # 递归出口
                return min(nums1[i1], nums2[i2])
            else:
                # 两边都有元素
                # 找到新的边界元素的下标,但需要考虑边界值，如i1 + k//2>length1?
                new_i1 = min(i1 + k // 2, length1) - 1
                new_i2 = min(i2 + k // 2, length2) - 1

                if nums1[new_i1] < nums2[new_i2]:
                    k = k - new_i1 + i1 - 1
                    i1 = new_i1 + 1
                else:
                    k = k - new_i2 + i2 - 1
                    i2 = new_i2 + 1
            return getKthnum(k, i1, i2)

        length = length1 + length2
        if length % 2 == 1:
            return getKthnum((length + 1) // 2, 0, 0)
        else:
            return (getKthnum(length // 2, 0, 0) +
                    getKthnum(length // 2 + 1, 0, 0)) / 2


if __name__ == '__main__':
    s = Solution()
    # nums1 = [1, 3]
    # nums2 = [2]

    nums1 = [2]
    nums2 = [1, 3, 4]

    # nums1 = [0, 0, 0, 0, 0]
    # nums2 = [-1, 0, 0, 0, 0, 0, 1]

    # nums1 = [1, 2, 3]
    # nums2 = [2, 3, 4, 5]
    # nums1 = [0, 0]
    # nums2 = [0, 0]
    print(s.findMedianSortedArrays(nums1=nums1, nums2=nums2))
