#include <iostream>
#include <string>
#include <vector>
using namespace ::std;
class Solution
{
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        int len = prices.size();
        if (len == 1)
            return 0;
        //用来记录那些稳赚不赔的卖出点，在判断的时候可以在此点开始，用以减少循环次数
        int last_sell = 0;
        vector<int> dp(len, 0);
        //但凡超过2的涨幅（>2）都是赚的
        for (int i = 1; i < len; i++)
        {
            dp[i] = dp[i - 1];
            for (int j = last_sell; j < i; j++)
            {
                if (dp[j] + prices[i] - prices[j] - fee > dp[i])
                {
                    dp[i] = dp[j] + prices[i] - prices[j] - fee;
                    last_sell = j;
                }
            }
        }
        return dp[len - 1];
    }
};