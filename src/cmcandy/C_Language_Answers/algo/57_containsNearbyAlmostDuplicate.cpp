#include <map>
#include <iostream>
#include <vector>
using namespace ::std;
class Solution
{
public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t)
    {
        map<int, int> m;
        int len = nums.size();
        for (int i = 0; i < len; i++)
        {
            int key = getKey(nums[i], (long)t + 1);
            if (m.count(key))
                return true;
            else if (m.count(key - 1) && abs((long)nums[i] - m[key - 1]) <= t)
                return true;
            else if (m.count(key + 1) && abs((long)nums[i] - m[key + 1]) <= t)
                return true;
            m[key] = nums[i];
            if (i >= k)
            {
                m.erase(getKey(nums[i - k], (long)t + 1));
            }
        }
        return false;
    }
    int getKey(int num, long t)
    {
        return num < 0 ? num / t - 1 : num / t;
    }
};
int main()
{
    Solution s;
    // vector<int> nums = {1, 5, 9, 1, 5, 9};
    vector<int> nums = {2147483647,-1,2147483647};

    // cout << s.containsNearbyAlmostDuplicate(nums, 2, 3);
    cout << s.containsNearbyAlmostDuplicate(nums, 1, 2147483647);
}