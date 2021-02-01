#include <iostream>
#include <vector>
#include <map>
using namespace ::std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int now = nums[0];
        int res = nums[0];
        int len = nums.size();

        for (int i = 1; i < len; i++)
        {
            //清0
            if (now < 0)
                now = 0;
            //记录当前值
            now += nums[i];
            //记录最大值
            res = res < now ? now : res;
        }
        return res;
    }
};