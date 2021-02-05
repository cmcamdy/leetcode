#include <iostream>
#include <vector>
using namespace ::std;
class Solution
{
public:
    int massage(vector<int> &nums)
    {
        int len = nums.size();
        //基本情况
        switch (len)
        {
        case 1:
            return 0;
        case 2:
            return nums[0];
        case 3:
            return nums[0] > nums[1] ? nums[0] : nums[1];
        default:
            break;
        }
        // if (len == 0)
        //     return 0;
        // if (len == 1)
        //     return nums[0];
        // if (len == 2)
        //     return nums[0] > nums[1] ? nums[0] : nums[1];
        vector<int> dp(len, 0);
        int tmp;
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < len; i++)
        {
            tmp = dp[i - 2] + nums[i];
            dp[i] = tmp > dp[i - 1] ? tmp : dp[i - 1];
        }
        return dp[len - 1];
    }
};