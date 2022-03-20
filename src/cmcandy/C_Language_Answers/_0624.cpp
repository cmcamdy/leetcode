#include <iostream>
#include <algorithm>
#include <vector>
using namespace ::std;
class Solution
{
public:
    vector<int> smallestRange(vector<vector<int>> &nums)
    {
        // 全部遍历一遍，然后记住最小窗口即可

        // 首先得合并窗口，并且记录该元素属于某个num数组，出现相同的不用怕，因为有第二个组数下表不一样，因此用到了pair结构
        vector<pair<int, int>> orders;
        for (int i = 0; i < nums.size(); i++)
        {
            for (auto &num : nums[i])
                orders.push_back({num, i});
        }
        sort(orders.begin(), orders.end());

        // 然后开始用滑动窗口遍历数组
        // 规则是当不满足要求的时候，窗口向右扩张，当满足的时候，窗口左侧向右收缩，直到快要不满足的边缘为止。
        //
        int count = 0, index = 0;
        vector<int> ans;
        vector<int> tags(nums.size(), 0);
        for (int i = 0; i < orders.size(); i++)
        {
            tags[orders[i].second]++;
            if (tags[orders[i].second] == 1)
                count++;
            if (count == nums.size())
            {
                while (tags[orders[index].second] > 1)
                    --tags[orders[index++].second];
                if (ans.empty() || ans[1] - ans[0] > orders[i].first - orders[index].first)
                    ans = vector<int>{orders[index].first, orders[i].first};
            }
        }
        return ans;
    }
};