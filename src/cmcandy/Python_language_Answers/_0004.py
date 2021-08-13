from typing import List


class Solution:
    def findMedianSortedArrays(self, nums1: List[int],
                               nums2: List[int]) -> float:
        # 首先需要知道长度
        len1 = len(nums1)
        len2 = len(nums2)
        # 交换值，这里保证了nums1是比较短的数组
        if len1 > len2:
            tmp = nums1
            nums1 = nums2
            nums2 = tmp
            tmp = len1
            len1 = len2
            len2 = tmp

        iMin = 0
        iMax = len1
        # 数组总长的一半
        halfLen = int((len1 + len2 + 1) / 2)

        while iMin <= iMax:
            i = int((iMin + iMax) / 2)
            j = halfLen - i
            if i < iMax and nums2[j - 1] > nums1[i]:
                iMin = i + 1
            elif i > iMin and nums1[i - 1] > nums2[j]:
                iMax = i - 1
            else:
                maxLeft = 0
                if i == 0:
                    maxLeft = nums2[j - 1]
                elif j == 0:
                    maxLeft = nums1[i - 1]
                else:
                    maxLeft = max(nums1[i - 1], nums2[j - 1])
                if (len1 + len2) % 2 == 1:
                    return maxLeft

                minRight = 0
                if i == len1:
                    minRight = nums2[j]
                elif j == len2:
                    minRight = nums1[i]
                else:
                    minRight = min(nums1[i], nums2[j])
                return (maxLeft + minRight) / 2
        return 0.0


if __name__ == '__main__':
    s = Solution()
    nums1 = [1, 2, 3]
    nums2 = [2, 3, 4, 5]
    # nums1 = [0, 0]
    # nums2 = [0, 0]
    print(s.findMedianSortedArrays(nums1=nums1, nums2=nums2))
