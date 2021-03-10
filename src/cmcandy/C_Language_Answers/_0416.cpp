#include <iostream>
#include <string>
#include <vector>
using namespace ::std;
//同1049
class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int len = nums.size();
        if (len == 1)
            return false;
        int sum = 0;
        for (int i = 0; i < len; i++)
        {
            sum += nums[i];
        }
        int target = sum / 2;
        vector<int> dp(target + 1, 0);
        //接下来就是背包问题了
        for (int i = 0; i < len; i++)
        {
            int val = nums[i];
            for (int j = target; j >= val; j--)
            {
                dp[j] = max(dp[j], dp[j - val] + val);
            }
        }
        return sum - 2 * dp[target] == 0 ? true : false;
    }
};