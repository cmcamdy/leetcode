#include <iostream>
#include <vector>
#include <map>
using namespace ::std;
class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        if (nums[right] < target)
            return nums.size();
        else if (nums[right] == target)
            return right;
        else if (nums[0] >= target)
            return 0;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] < target)
            {
                if (nums[mid + 1] > target)
                    return mid + 1;
                else
                    left = mid;
            }
            else if (nums[mid] == target)
            {
                return mid;
            }
            else
            {
                right = mid;
            }
        }
        return -1;
    }
};