#include <iostream>
#include <vector>
#include <limits.h>
using namespace ::std;
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int len = nums.size();
        if (len == 1)
            return true;
        int step = nums[0];
        //最后一个不需要判断，能走到即是胜利
        for (int i = 0; i < len - 1; i++)
        {
            //如果比step大说明按这格可以跳得更远
            if (nums[i] > step)
                step = nums[i];
            //判断能不能到跳过这个0
            if (step == 0 && nums[i] == 0)
                return false;
            step--;
        }
        return true;
    }
};