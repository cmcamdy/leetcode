#include <iostream>
#include <vector>
#include <math.h>

using namespace ::std;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.size() == 0)
            return 0;
        int pro = 0;
        int buy = prices[0];
        for (int i = 1; i < prices.size(); i++)
        {
            //这种情况是倒数
            pro = max(prices[i] - buy, pro);
            if (buy > prices[i])
                buy = prices[i];
        }
        return pro;
    }
};