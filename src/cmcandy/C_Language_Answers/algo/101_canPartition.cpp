#include <iostream>
#include <vector>
#include <string>
using namespace ::std;
class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int len = nums.size();
        int sum = 0;
        for (int i = 0; i < len; i++)
        {
            sum += nums[i];
        }
        if (sum % 2 != 0)
            return false;
        int half = sum / 2;
        // 转换为0-1背包问题，ret 能不能被装满T/F
        vector<vector<int>> dp(len + 1, vector<int>(half + 1));
        for (int i = 1; i <= len; i++)
        {
            for (int j = 0; j <= half; j++)
            {
                dp[i][j] = dp[i - 1][j];
                if (j >= nums[i - 1])
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - nums[i - 1]] + nums[i - 1]);
            }
        }
        return dp[len][half] == half;
    }
};