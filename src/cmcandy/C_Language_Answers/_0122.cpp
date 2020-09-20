#include <iostream>
#include <vector>

using namespace ::std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {

        if (prices.size() == 0)
            return 0;
        int pro = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            pro += prices[i] > prices[i - 1] ? prices[i] - prices[i - 1] : 0;
        }
        return pro;
    }
};