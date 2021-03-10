#include <iostream>
#include <string>
#include <vector>
using namespace ::std;

//同416
class Solution
{
public:
    int lastStoneWeightII(vector<int> &stones)
    {
        //将这堆石头分成大小尽量相近的两堆
        //自己先求出target，转化成背包问题
        int len = stones.size();
        if (len == 1)
            return stones[0];
        int sum = 0;
        for (int i = 0; i < len; i++)
        {
            sum += stones[i];
        }
        int target = sum / 2;
        vector<int> dp(target + 1, 0);
        //接下来就是背包问题了
        for (int i = 0; i < len; i++)
        {
            int val = stones[i];
            for (int j = target; j >= val; j--)
            {
                dp[j] = max(dp[j], dp[j - val] + val);
            }
        }
        return sum - 2 * dp[target];
    }
};