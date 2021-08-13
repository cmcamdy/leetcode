class Solution:
    def reverse(self, x: int) -> int:
        s = ''
        if x < 0:
            s += '-'
            x *= -1
        else:
            s += '0'
        while x > 0:
            tmp = x % 10
            s += str(tmp)
            x = x // 10
        res = int(s)
        if res > 2**31 - 1 or res < - 2**31:
            return 0
        else:
            return res
        




if __name__ == '__main__':
    s = Solution()
    print(s.reverse(1534236469))
    