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
        if (len <= 1)
            return len;

        // 表示以此为结尾的最大的增长序列长度
        vector<int> dp(len, 1);

        int max_num = 1, max_res = 1;
        for (int i = 1; i < len; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                {
                    max_num = max(dp[j] + 1, max_num);
                }
            }
            dp[i] = max_num;
            max_res = max(max_res, max_num);
            max_num = 1;
        }
        return max_res;
    }


    // // 这个也能过，就是时间用的多点，思路是二维dp
    // int lengthOfLIS(vector<int> &nums)
    // {
    //     //当前递增数now、最大递增数res
    //     int len = nums.size();
    //     if (len <= 1)
    //         return len;
    //     int res = 0;
    //     vector<vector<int>> dp(len, vector<int>(len, 1));
    //     for (int i = 1; i < len; i++)
    //     {
    //         dp[i][0] = nums[i]>nums[0]?2:1;
    //         //找到第一个小于该数的值，在此基础上++，有问题
    //         for (int j = 1; j <= i; j++)
    //         {
    //             if (nums[i] > nums[j])
    //                 dp[i][j] = max(dp[j][j]+1, dp[i][j - 1]);
    //             else
    //                 dp[i][j] = dp[i][j - 1];
    //         }
    //         res = max(res,dp[i][i]);
    //     }
    //     return res;
    // }
};
int main(int argc, char const *argv[])
{
    // int num[8] = {10,9,2,5,3,7,101,18};
    // vector<int> num{10, 9, 2, 5, 3, 7, 101, 18};
    // vector<int> num{1, 3, 6, 7, 9, 4, 10, 5, 6};
    vector<int> num{4, 10, 4, 3, 8, 9};
    Solution s;
    int res = s.lengthOfLIS(num);
    cout << res;
}
