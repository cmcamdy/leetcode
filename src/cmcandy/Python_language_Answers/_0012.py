class Solution:
    def intToRoman(self, num: int) -> str:
        tmp = 0
        res = ''
        lis = ['I', 'V', 'X', 'L', 'C', 'D', 'M']
        dig = 0
        while num > 0:
            tmp = num % 10
            num //= 10
            if tmp < 4 and tmp > 0:
                res = lis[dig] * tmp + res
            elif tmp == 4:
                res = lis[dig] + lis[dig + 1] + res
            elif tmp == 5:
                res = lis[dig + 1] + res
            elif tmp < 9 and tmp > 5:
                res = lis[dig + 1] + lis[dig] * (tmp - 5) + res
            elif tmp == 9:
                res = lis[dig] + lis[dig + 2] + res

            dig += 2
        return res


if __name__ == '__main__':
    s = Solution()
    s.intToRoman(10)