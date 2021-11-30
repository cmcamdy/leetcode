

#include <algorithm>
#include <vector>
#include <iostream>
using namespace ::std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {

        int len = nums.size();
        sort(nums.begin(), nums.end());
        int left = 0, mid = 1, right = len - 1;
        vector<vector<int>> res;

        for (int i = 0; i < len - 2; i++)
        {
            if ((i >= 1 && nums[i - 1] == nums[i]))
                continue;
            if (nums[i] > 0)
                break;
            right = len - 1;
            left = i + 1;
            while (right > left)
            {
                if (nums[right] + nums[i] + nums[left] > 0)
                {
                    right--;
                }
                else if (nums[right] + nums[i] + nums[left] < 0)
                {
                    left++;
                }
                else
                {
                    //可以匹配
                    vector<int> tmp = {nums[i], nums[left], nums[right]};
                    res.push_back(tmp);
                    while (left < right && nums[left] == nums[left + 1])
                        left++;
                    while (left < right && nums[right] == nums[right - 1])
                        right--;
                    left++;
                    right--;
                }
            }
        }
        return res;
    }
};