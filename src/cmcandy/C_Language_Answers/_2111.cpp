#include <iostream>
#include <vector>
#include <string>
using namespace ::std;

// 对于给定的一个序列，如果我们希望通过修改最少的元素，使得它单调递增，那么最少需要修改的元素个数，就是「序列的长度」减去「序列的最长递增子序列」的长度。
class Solution
{
public:
    int kIncreasing(vector<int> &arr, int k)
    {
        //当前递增数now、最大递增数res
        int len = arr.size();
        if (len <= 1)
            return 0;
        // 主要是为了得到最长字串
        // 表示以此为结尾的最大的增长序列长度
        vector<int> dp(len, 1);
        int res = 0;
        for (int i = 0; i < k; i++)
        {
            res += lengthOfLIS(arr, dp, k, i);
        }
        return res;
    }

    int lengthOfLIS(vector<int> &nums, vector<int> &dp, int k, int start)
    {

        int max_num = 1, max_res = 1, count = 1;
        for (int i = start + k; i < nums.size(); i += k)
        {
            for (int j = i-k; j >= 0; j -= k)
            {
                if (nums[j] <= nums[i])
                {
                    max_num = max(dp[j] + 1, max_num);
                }
            }
            dp[i] = max_num;
            max_res = max(max_res, max_num);
            max_num = 1;
            count++;
        }
        return count - max_res;
    }
};
int main()
{
    Solution s;
    vector<int> arr = {5, 4, 3, 2, 1};
    int k = 1;

    // vector<int> arr = {4, 1, 5, 2, 6, 2};
    // int k = 2;
    // int k = 3;

    cout << s.kIncreasing(arr, k);
}