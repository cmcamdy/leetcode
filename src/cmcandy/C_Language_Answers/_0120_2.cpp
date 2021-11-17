#include <iostream>
#include <math.h>
#include <vector>
using namespace ::std;
class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int len = triangle.size();
        if (len == 1)
            return triangle[0][0];
        int dp[len][len];
        dp[0][0] = triangle[0][0];
        // dp[0][1] = dp[0][0]+triangle[0][1];
        // dp[1][1] = dp[0][0]+triangle[1][1];
        // if (len == 2) return max(dp[0][1],dp[1][1]);
        for (int i = 1; i < len; i++)
        {
            //两条对角线的值，只有一种可能
            dp[i][i] = dp[i - 1][i - 1] + triangle[i][i];
            dp[i][0] = dp[i-1][0] + triangle[i][0];
            for (int j = 1; j < i; j++)
            {
                dp[i][j] = min(dp[i - 1][j - 1], dp[i-1][j]) + triangle[i][j];
            }
        }
        int res = 10000;
        for (int j = 0; j < len; j++)
        {
            res = min(dp[len - 1][j], res);
        }
        return res;
    }
};
int main(int argc, char const *argv[])
{
    Solution s;
    vector<vector<int>> triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    s.minimumTotal(triangle);
    return 0;
}
