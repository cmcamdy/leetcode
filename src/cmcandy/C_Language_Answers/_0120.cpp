#include <iostream>
#include <math.h>
#include <vector>
using namespace ::std;
class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        //动态规划
        vector<vector<int>> dp;
        int len = triangle.size();
        int res = 100000;
        for (int i = 0; i < len; i++)
        {
            vector<int> dp2(i + 1, 0);
            //第一行
            if (i == 0)
            {
                dp2[0] = triangle[0][0];
                dp.push_back(dp2);
            }
            else
            {
                //上一行的+本行的权重
                dp2[0] = dp[i - 1][0] + triangle[i][0];
                dp2[i] = dp[i - 1][i - 1] + triangle[i][i];
                for (int j = 1; j < i; j++)
                {
                    //本行权重+上行小值
                    dp2[j] = triangle[i][j] + min(dp[i - 1][j - 1], dp[i - 1][j]);
                }
                dp.push_back(dp2);
            }
        }
        res = dp[len - 1][0];
        for (int i = 1; i < len; i++)
        {
            //遍历最后一行
            res = min(res, dp[len - 1][i]);
        }
        return res;
    }
};