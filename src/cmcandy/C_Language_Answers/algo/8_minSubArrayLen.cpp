#include <iostream>
#include <vector>
using namespace ::std;

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int len = nums.size();
        if (len == 1)
            return target > nums[0] ? 0 : 1;
        int left = 0, right = 0;
        int res = 10000, now = nums[0];
        while (left <= right && right < len - 1)
        {
            if (now < target)
            {
                right++;
                now += nums[right];
            }
            else
            {
                res = min(res, right - left + 1);
                now -= nums[left];
                left++;
            }
        }
        while (now >= target)
        {
            res = min(res, right - left + 1);
            now -= nums[left++];
        }
        return res == 10000 ? 0 : res;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    cout << s.minSubArrayLen(7, nums);
}