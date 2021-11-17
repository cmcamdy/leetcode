class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        # dp = [[0] * (len(s) + 1)] * (len(t) + 1)
        dp = [[0] * (len(s) + 1)  for index in range(len(t)+1)]
        dp[0] = [1] * (len(s) + 1)
        # print(dp)
        for i in range(1, len(t) + 1):
            for j in range(1, len(s) + 1):
                if (s[j - 1] == t[i - 1]):
                    dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1]
                else:
                    dp[i][j] = dp[i][j - 1]
        return dp[len(t)][len(s)]


if __name__ == '__main__':
    s = Solution()
    print(s.numDistinct('rabbbit','rabbit'))