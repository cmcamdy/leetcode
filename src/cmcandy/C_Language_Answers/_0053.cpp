#include <iostream>
#include <vector>
#include <limits.h>
using namespace ::std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int max = INT_MIN, tmp = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            tmp = tmp <= 0 ? nums[i] : nums[i] + tmp;
            max = max > tmp ? max : tmp;
        }
        return max;
    }
};