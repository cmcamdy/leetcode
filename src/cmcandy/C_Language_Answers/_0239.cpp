#include <iostream>
#include <vector>
#include <queue>
using namespace ::std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> q;
        vector<int> res;

        // 加载窗口
        int index = 0;
        for (int i = 0; i < k; i++)
        {
            if (index < q.size() && nums[q.back()] < nums[i])
                while (index < q.size() && nums[q.back()] <= nums[i])
                {
                    q.pop_back();
                }
            q.push_back(i);
        }
        res.push_back(nums[q[index]]);

        // 滑动窗口
        for (int i = k; i < nums.size(); i++)
        {
            if (i - q[index] >= k)
                index++;
            if (index < q.size() && nums[q.back()] < nums[i])
                while (index < q.size() && nums[q.back()] <= nums[i])
                {
                    q.pop_back();
                }
            q.push_back(i);

            res.push_back(nums[q[index]]);
        }
        return res;
    }
};
int main()
{
    Solution s;
    // vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    // vector<int> nums = {1, 3, 1, 2, 0, 5};
    vector<int> nums = {9, 10, 9, -7, -4, -8, 2, -6};

    // s.maxSlidingWindow(nums, 3);
    s.maxSlidingWindow(nums, 5);
}