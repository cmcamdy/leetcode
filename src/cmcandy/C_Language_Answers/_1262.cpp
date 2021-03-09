#include <iostream>
#include <vector>
#include <limits.h>
using namespace ::std;
class Solution
{
public:
    int maxSumDivThree(vector<int> &nums)
    {
        //将nums分类，计算sum，得到余数remain
        int len = nums.size();
        int sum = 0;
        vector<vector<int>> dp(3, vector<int>(2, 100000));
        for (int i = 0; i < len; i++)
        {
            sum += nums[i];
            int tmp = nums[i] % 3;
            //保留最小的两个备用即可(0和1各两个)
            if (nums[i] < dp[tmp][0])
            {
                dp[tmp][1] = dp[tmp][0];
                dp[tmp][0] = nums[i];
            }
            else if (nums[i] < dp[tmp][1])
                dp[tmp][1] = nums[i];
        }
        if (sum % 3 == 0)
            return sum;
        else if (sum % 3 == 1)
            return max(sum - dp[1][0], sum - dp[2][0] - dp[2][1]) > 0 ? max(sum - dp[1][0], sum - dp[2][0] - dp[2][1]) : 0;
        else if (sum % 3 == 2)
            return max(sum - dp[2][0], sum - dp[1][0] - dp[1][1]) > 0 ? max(sum - dp[2][0], sum - dp[1][0] - dp[1][1]) : 0;
        return 0;
    }
};

// int main(int argc, char const *argv[])
// {
//     Solution s;
//     vector<int> nums{5, 2, 2, 2};
//     cout << s.maxSumDivThree(nums);
//     return 0;
// }
