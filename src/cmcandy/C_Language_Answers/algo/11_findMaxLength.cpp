#include <iostream>
#include <vector>
#include <map>
using namespace ::std;

class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        // 用map记录差值，然后每次找到sum的时候从map中找对应的，如果没有，则当前sum的位置是最早的，有则出现了一组符合条件的子数组，计算长度
        map<int, int> m;
        m[0] = -1;
        int len = nums.size();
        int sum = 0;
        int res = 0;
        for (int i = 0; i < len; i++)
        {
            sum += nums[i] == 0 ? -1 : 1;
            if (m.find(sum) == m.end())
            {
                m[sum] = i;
            }
            else
            {
                res = max(res, i - m[sum]);
            }
        }
        return res;
    }
};