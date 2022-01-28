#include <iostream>
#include <vector>
#include <string>
using namespace ::std;
#define INT_MAX 2147483647
// 题目中明确最终答案可以用 int 表示，但是实际在计算中会出现大数，对于这些出现大数的状态可以不进行计算，因为最终答案不会由这些出现大数的状态得到。
// https://leetcode-cn.com/problems/D0F0SV/solution/jian-zhi-offer-2-mian-shi-ti-104-shu-zho-fm4p/

class Solution
{
public:
    int combinationSum4(vector<int> &nums, int target)
    {
        // int len = nums.size();
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 0; i <= target; i++)
        {
            for (auto &num : nums)
            {
                if (i >= num && dp[i - num] <= INT_MAX - dp[i])
                    dp[i] += dp[i - num];
            }
        }
        return dp[target];
    }
};