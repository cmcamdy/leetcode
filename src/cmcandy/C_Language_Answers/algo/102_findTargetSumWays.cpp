#include <iostream>
#include <vector>
#include <string>
using namespace ::std;
class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int len = nums.size();
        if (len == 1)
            return (nums[0] == target || -nums[0] == target) ? 1 : 0;
        int sum = 0;
        for (auto &num : nums)
        {
            sum += num;
        }
        if ((sum - target) % 2 != 0 || sum < target)
            return 0;
        int neg = (sum - target) / 2;
        // neg就是新的target，这就变成了背包问题
        vector<vector<int>> dp(len, vector<int>(neg + 1, 0));
        dp[0][0] = 1;
        // for(int i=0; i<len; i++){
        //     dp[i][0]=1;
        // }
        if (nums[0] <= neg)
            dp[0][nums[0]] += 1;
        for (int i = 1; i < len; i++)
        {
            for (int j = 0; j <= neg; j++)
            {
                dp[i][j] = dp[i - 1][j];
                if (j >= nums[i])
                {
                    dp[i][j] += dp[i - 1][j - nums[i]];
                }
            }
        }
        return dp[len - 1][neg];
    }
};