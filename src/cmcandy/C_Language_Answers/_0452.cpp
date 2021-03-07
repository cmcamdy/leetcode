#include <iostream>
#include <vector>
#include<algorithm>
using namespace ::std;

class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {

        int len = points.size();
        int arrow = 1;
        int tmp;
        if (len <= 1)
            return len;
        //尾部排序
        sort(points.begin(), points.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[1] < b[1];
        });
        tmp = points[0][1];
        for (int i = 1; i < len; i++)
        {
            if (points[i][0] > tmp)
            {
                tmp = points[i][1];
                arrow++;
            }
        }
        return arrow;
    }
};