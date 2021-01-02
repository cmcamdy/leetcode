#include <iostream>
#include <vector>

using namespace ::std;
class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        //动规即可
        int len = cost.size();
        //基本情况，好像不用考虑也可以通过
        // if(len==1) return 0;
        // else if(len==2) return min(cost[0],cost[1]);
        //填数组
        for (int i = 2; i < len; i++)
            cost[i] += min(cost[i - 1], cost[i - 2]);
        //决定方案
        return min(cost[len - 2], cost[len - 1]);
    }
};