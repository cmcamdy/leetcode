#include <vector>
#include <iostream>
using namespace ::std;

class Solution
{
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k)
    {
        int len = nums.size();
        int left = 0, right = 0;
        int count = 0;
        long now = 1;
        for (; right < len; right++)
        {
            now *= nums[right];
            while (left <= right && now >= k)
                now /= nums[left++];
            count += right >= left ? right - left + 1 : 0;
        }
        return count;
    }
};