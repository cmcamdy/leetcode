#include <iostream>
#include <vector>
#include <algorithm>
using namespace ::std;
class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        //排序
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        //从贪心的角度考虑，每次满足胃口最小的孩子可以满足最多的孩子
        int sum = 0;
        int glen = g.size();
        int slen = s.size();
        // 贪心思想，j++但sum不++代表着这块饼干被丢弃（因为孩子只能吃一块）
        for (int i = 0, j = 0; i < slen && sum < glen; i++, j++)
        {
            if (g[sum] <= s[i])
                sum++;
        }
        return sum;
    }
};
