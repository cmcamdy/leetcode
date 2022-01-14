#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace ::std;

class Solution
{
public:
    int n, k;
    vector<int> path;
    vector<vector<int>> res;
    vector<vector<int>> combine(int n, int k)
    {

        this->n = n;
        this->k = k;
        // 从1开始
        backtrace(1);
        return res;
    }
    void backtrace(int num)
    {
        if (num > n)
        {
            if (path.size() == k)
                res.push_back(path);
            return;
        }
        // 没有num的子集
        backtrace(num + 1);

        // 有num的子集
        if (path.size() < k)
        {
            path.push_back(num);
            backtrace(num + 1);
            path.pop_back();
        }
    }
};