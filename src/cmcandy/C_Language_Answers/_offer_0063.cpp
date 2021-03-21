#include <iostream>
#include <vector>
using namespace ::std;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int res = 0;
        int len = prices.size();
        if (len <= 1)
            return 0;
        //找到前i个的最小即可
        int tmp_min = prices[0];
        for (int i = 1; i < len; i++)
        {
            if (tmp_min > prices[i])
                tmp_min = prices[i];
            else if (tmp_min < prices[i])
                res = max(res, prices[i] - tmp_min);
        }
        return res;
    }
};