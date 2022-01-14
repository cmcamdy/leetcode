#include <iostream>
#include <vector>
#include <string>
using namespace ::std;

class Solution
{
public:
    int minCutminCut(string s)
    {
        int len = s.size();
        // 构造dp，表示s[i-j]的数组是否是一个回文
        vector<vector<int>> dp(len, vector<int>(len, true));
        for (int i = len - 1; i >= 0; i--)
        {
            for (int j = i + 1; j < len; ++j)
            {
                dp[i][j] = (s[i] == s[j]) && dp[i + 1][j - 1];
            }
        }
        // f表示s[0-i]需要多少次割（min）
        vector<int> f(len, 2000);
        for (int i = 0; i < len; i++)
        {
            if (dp[0][i])
            {
                f[i] = 0;
            }
            else
            {
                for (int j = 0; j < i; j++)
                {
                    if (dp[j + 1][i])
                    {
                        f[i] = min(f[i], f[j] + 1);
                    }
                }
            }
        }
        return f[len - 1];
    }
};