#include <iostream>
#include <vector>
#include <map>
using namespace ::std;
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        // 利用map记录下各个sum出现的个数（前i个元素和），然后当前sum - sumh就可以得到一堆连续的子数组，如果这个值刚好等于k则这组-sumh得到的子数组满足要求，加上sumh出现的个数即可
        map<int, int> m;
        m[0] = 1;
        int sum = 0, count = 0;
        int len = nums.size();
        for (int i = 0; i < len; i++)
        {
            sum += nums[i];
            count += (m.find(sum - k) != m.end()) ? m[sum - k] : 0;
            m[sum] = (m.find(sum) != m.end()) ? m[sum] + 1 : 1;
        }
        return count;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {1, -1, 0};

    cout << s.subarraySum(nums, 0);
}