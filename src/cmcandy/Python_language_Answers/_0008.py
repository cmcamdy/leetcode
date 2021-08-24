class Solution:
    def myAtoi(self, s: str) -> int:
        length = len(s)
        index = 0
        symbol = 1
        num = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']
        while index < length and s[index] == ' ':
            # 前导空格
            index += 1
        if index < length and s[index] == '+':
            # 正还是负号
            index += 1
        elif index < length and s[index] == '-':
            index += 1
            symbol = -1
        tmp = 0
        while index < length and s[index] in num:
            # 非数字字符或到达输入的结尾
            tmp *= 10
            tmp += int(s[index])
            index += 1
        # 如果整数数超过 32 位有符号整数范围，固定在边界值
        tmp *= symbol
        if tmp > 2**31 - 1:
            tmp = 2**31 - 1
        elif tmp < -2**31:
            tmp = -2**31
        return tmp


if __name__ == '__main__':
    s = Solution()
    print(s.myAtoi(' -42'))