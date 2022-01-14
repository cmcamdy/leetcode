#include <iostream>
#include <vector>
#include <algorithm>
using namespace ::std;
class Solution
{
public:
    // 二维vector排序：https://blog.csdn.net/liguojie12/article/details/113800426

    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b)
             { return a[0] < b[0]; }); //速度比方法1稍慢
        vector<int> tmp = intervals[0];
        vector<vector<int>> res;
        for (int i = 1; i < intervals.size(); i++)
        {
            if (tmp[1] < intervals[i][0])
            {
                res.push_back(tmp);
                tmp = intervals[i];
            }
            else
            {
                tmp[0] = min(intervals[i][0], tmp[0]);
                tmp[1] = max(intervals[i][1], tmp[1]);
            }
        }
        res.push_back(tmp);
        return res;
    }
};
int main()
{
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    Solution s;
    s.merge(intervals);
}