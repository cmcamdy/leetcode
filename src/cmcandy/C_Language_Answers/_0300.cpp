#include <iostream>
#include <vector>

using namespace ::std;
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        //当前递增数now、最大递增数res
        int len = nums.size();
        if (len == 0)
            return 0;
        int res = 0;
        vector<vector<int>> dp(len, vector<int>(len, 1));
        for (int i = 1; i < len; i++)
        {
            dp[i][0] = nums[i]>nums[0]?2:1;
            //找到第一个小于该数的值，在此基础上++，有问题
            for (int j = 1; j <= i; j++)
            {
                if (nums[i] > nums[j])
                    dp[i][j] = max(dp[j][j]+1, dp[i][j - 1]);
                else
                    dp[i][j] = dp[i][j - 1];
            }
            res = max(res,dp[i][i]);
        }
        return res;
    }
};
int main(int argc, char const *argv[])
{
    // int num[8] = {10,9,2,5,3,7,101,18};
    // vector<int> num{10, 9, 2, 5, 3, 7, 101, 18};
    vector<int> num{1,3,6,7,9,4,10,5,6};
    Solution s;
    int res = s.lengthOfLIS(num);
    return res;
}
