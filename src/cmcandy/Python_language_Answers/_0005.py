# 动态规划法


class Solution:
    def longestPalindrome(self, s: str) -> str:

        length = len(s)
        if length == 1:
            return s[0]
        maxlen = [0, 0]
        # 初始化一个动规数组
        # lis[i,j]表示s[i]-s[j]是否是一个回文字符串
        # l = [0 for i in range(length)]
        lis = [[0 for i in range(length)] for i in range(length)]
        # 初始化数组（对角线）
        for index in range(length):
            lis[index][index] = 1
            if index < (length - 1) and s[index] == s[index + 1]:
                lis[index][index + 1] = 1
                maxlen = [index, index + 1]
        # 斜对角初始化数组
        if length > 2:
            for i in range(2, length):
                for j in range(i, length):
                    if s[j - i] == s[j] and lis[j - i + 1][j - 1] == 1:
                        lis[j - i][j] = 1
                        maxlen = [j - i, j]

        return s[maxlen[0] : maxlen[1] + 1]

if __name__ == '__main__':
    s = Solution()
    # s.longestPalindrome('babad')
    print(s.longestPalindrome('cbbd'))
    