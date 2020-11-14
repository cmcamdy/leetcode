#include <iostream>
#include <string>
#include <vector>
using namespace ::std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int len = nums.size();
        int left = 0, right = len - 1;
        int mid;
        while (left <= right)
        {
            mid = (left + right) / 2;
            if (nums[mid] > target)
                right = mid - 1;
            else if (nums[mid] < target)
                left = mid + 1;
            else
                return mid;
        }
        return -1;
    }
};