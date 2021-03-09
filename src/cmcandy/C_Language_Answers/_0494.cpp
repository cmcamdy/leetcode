#include <iostream>
#include <string>
#include <vector>
using namespace ::std;
class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int S)
    {
        //得到nums的个数，然后穿begin和end，进行递归
        int len = nums.size();
        return help(0, 0, len - 1, nums, S);
    }

    int help(int now, int begin, int end, vector<int> &nums, int S)
    {
        int res;
        //走到底，退出
        if (begin == end)
        {
            res = (nums[begin] + now) == S ? 1 : 0;
            res += (-nums[begin] + now) == S ? 1 : 0;
            return res;
        }
        else
        {
            //没走到底，继续循环,左右两侧算出后返回
            res = help(now + nums[begin], begin + 1, end, nums, S);
            res += help(now - nums[begin], begin + 1, end, nums, S);
            return res;
        }
    }
};