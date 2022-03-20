#include <iostream>
#include <vector>
#include <map>
using namespace ::std;
class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int len = cost.size();
        vector<int> dp(len, 0);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < len; i++)
        {
            dp[i] = min(dp[i - 2], dp[i - 1]) + cost[i];
        }
        return min(dp[len - 1], dp[len - 2]);
    }
};

int main()
{
    vector<int> nums = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    Solution s;
    cout << s.minCostClimbingStairs(nums);
}