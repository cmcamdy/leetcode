#include <iostream>
#include <string>
#include <vector>
using namespace ::std;

class Solution
{
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k)
    {
        int left = 0;
        int tmp = 1, count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] >= k)
            {
                tmp = 1;
                left = i + 1;
            }
            else
            {
                tmp *= nums[i];
                while (tmp >= k)
                    tmp /= nums[left++];
                count += i - left + 1;
            }
        }
        return count;
    }
};