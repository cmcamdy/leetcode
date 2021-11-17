#include <iostream>
#include <vector>
using namespace ::std;

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int len = nums.size();
        int index = Binary(nums, 0, len - 1, target);
        if (index == -1)
        {
            return {-1, -1};
        }
        return {Binary_bound_left(nums, 0, index, target), Binary_bound_right(nums, index, len - 1, target)};
    }
    int Binary(vector<int> &nums, int left, int right, int target)
    {
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else if (nums[mid] > target)
            {
                right = mid - 1;
            }
        }
        return -1;
    }
    int Binary_bound_left(vector<int> &nums, int left, int right, int target)
    {
        if (nums[left] == target)
            return left;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] == target)
            {
                if (nums[mid - 1] != target)
                {
                    return mid;
                }
                else
                {
                    right = mid - 1;
                }
            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
        }
        return -1;
    }
    int Binary_bound_right(vector<int> &nums, int left, int right, int target)
    {
        if (nums[right] == target)
            return right;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] == target)
            {
                if (nums[mid + 1] != target)
                {
                    return mid;
                }
                else
                {
                    left = mid + 1;
                }
            }
            else if (nums[mid] > target)
            {
                right = mid - 1;
            }
        }
        return -1;
    }
};