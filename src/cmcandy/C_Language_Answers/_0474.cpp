#include <iostream>
#include <string>
#include <vector>
using namespace ::std;
class Solution
{
public:
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        int len = strs.size();
        //dp[i][j][k] i=len;j=m;k=n;
        // vector<vector<vector<int>>> dp(len+1,vector<int>(m+1,vector<int>(n+1)));
        int dp[len + 1][m + 1][n + 1];
        for (int j = 0; j <= m; j++)
            for (int k = 0; k <= n; k++)
                dp[0][j][k] = 0;

        //先数清每个串0，1个数
        // vector<vector<int>> tmp(len,vector<int>(2,0));
        int tmp[len][2];
        for (int i = 0; i < len; i++)
        {
            //count
            int cn = 0, cm = 0;
            for (int j = 0; j < strs[i].size(); j++)
                if (strs[i][j] == '0')
                    cm++;
                else if (strs[i][j] == '1')
                    cn++;
            tmp[i][0] = cm;
            tmp[i][1] = cn;
        }
        //再填dp
        //dp[i][j][k]   =dp[i-1][j][k]       (不放)
        //              =dp[i-1][j-m][k-n]+1 (放，这里注意需要考虑jk比mn小的问题,mn是某个字符串01个数)
        for (int i = 1; i <= len; i++)
            for (int j = 0; j <= m; j++)
                for (int k = 0; k <= n; k++)
                    if (k < tmp[i - 1][1] || j < tmp[i - 1][0])
                        //背包空间不够，不能放
                        dp[i][j][k] = dp[i - 1][j][k];
                    else
                        //背包空间足够，可以考虑放
                        dp[i][j][k] = max(dp[i - 1][j][k], dp[i - 1][j - tmp[i - 1][0]][k - tmp[i - 1][1]] + 1);
        return dp[len][m][n];
    }
};
int main(int argc, char const *argv[])
{
    Solution s;
    // string str[] = {"10", "0001", "111001", "1", "0"};
    // vector<string> strs(str, str + 5);
    // int res = s.findMaxForm(strs, 5, 3);

    string str[] = {"10", "0", "1"};
    vector<string> strs(str, str + 3);
    int res = s.findMaxForm(strs, 1, 1);

    cout << res;
    return 0;
}
