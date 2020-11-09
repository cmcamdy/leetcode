#include <iostream>
#include <string>
#include <vector>
using namespace ::std;
class Solution
{
public:
    int dominantIndex(vector<int> &nums)
    {
        int len = nums.size();
        if (len < 2)
            return 0;
        int fir = 1, sec = 0;
        if (nums[0] > nums[1])
        {
            fir = 0;
            sec = 1;
        }
        for (int i = 2; i < len; i++)
        {
            if (nums[i] > nums[sec])
            {
                if (nums[i] > nums[fir])
                {
                    sec = fir;
                    fir = i;
                }
                else
                    sec = i;
            }
        }
        return nums[fir] >= 2 * nums[sec] ? fir : -1;
    }
};