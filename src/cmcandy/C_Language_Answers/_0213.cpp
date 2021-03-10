#include <iostream>
#include <vector>
using namespace ::std;
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int len = nums.size();
        if (len == 1)
            return nums[0];
        else if (len == 2)
            return max(nums[0], nums[1]);
        //dp表示前n个最大金额
        //这里由于是环形的，故第一个和最后一个不能同时取到，所以分两次，第一次不取最后一个，第二次不取第一个，然后取二者的较大值即可
        vector<int> dp(len, 0);
        vector<int> dp2(len, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        dp2[0] = 0;
        dp2[1] = nums[1];
        for (int i = 2; i < len - 1; i++)
        {
            dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
            dp2[i] = max(nums[i] + dp2[i - 2], dp2[i - 1]);
        }
        dp2[len - 1] = max(nums[len - 1] + dp2[len - 3], dp2[len - 2]);
        return max(dp[len - 2], dp2[len - 1]);
    }
};