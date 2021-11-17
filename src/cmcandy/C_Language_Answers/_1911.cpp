#include <iostream>
#include <vector>
using namespace ::std;

class Solution
{
public:
    long long maxAlternatingSum(vector<int> &nums)
    {
        int len = nums.size();
        long long sum = nums[0];
        int pre = 0;

        for (int i = 0; i < len; i++)
        {
            if (i - pre < 2 && nums[i] > nums[pre])
            {
                sum = sum + nums[i] - nums[pre];
                pre = i;
            }
            else if (i - pre >= 2 && nums[i] > nums[i - 1])
            {
                sum = sum + nums[i] - nums[i - 1];
            }
        }
        return sum;
    }
};