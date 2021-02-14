#include <iostream>
#include <vector>
#include <algorithm>
using namespace ::std;

class Solution
{
public:
    //检查该gap是否满足
    bool check(int gap, vector<int> &position, int m)
    {
        int res = 1, last = position[0], len = position.size();
        for (int i = 0; i < len; i++)
        {
            if (position[i] >= last + gap)
            {
                last = position[i];
                res++;
            }
        }
        return res >= m;
    }
    int maxDistance(vector<int> &position, int m)
    {
        sort(position.begin(), position.end());
        //如果m>2，比如3
        int len = position.size();
        //题目所给gap=1是一定满足要求的
        int left = 0, right = position[len - 1] - position[0];
        int mid;
        int res = 1;
       
        while (left <= right)
        {
            mid = (left + right) / 2;
            if (check(mid, position, m))
            {
                //可以，则往大缩小范围
                res = mid;
                left = mid + 1;
            }
            else
                right = mid - 1;
        }
        return res;
    }
};
int main(int argc, char const *argv[])
{
    Solution s;
    // vector<int> position{1,2,3,4,7};
    vector<int> position{79, 74, 57, 22};
    int res = s.maxDistance(position, 3);
    cout<<res;
    return 0;
}
