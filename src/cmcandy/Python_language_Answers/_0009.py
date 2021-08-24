class Solution:
    def isPalindrome(self, x: int) -> bool:
        # 示例2中负数不是回文数
        if x < 0:
            return False
        # 做一下反转即可
        tmp = 0
        sourse = x
        while x > 0:
            tmp *= 10
            tmp += (x % 10)
            x //= 10
        return tmp == sourse


if __name__ == '__main__':
    s = Solution()
    s.isPalindrome(121)