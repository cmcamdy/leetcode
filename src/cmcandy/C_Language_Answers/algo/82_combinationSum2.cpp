#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace ::std;

class Solution
{
public:
    vector<int> candidates;
    int target, sum;
    vector<int> path;
    vector<vector<int>> res;
    map<int, int> m;
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        this->target = target;
        this->sum = 0;
        for (auto &num : candidates)
        {
            if (m.find(num) == m.end())
            {
                m[num] = 1;
                this->candidates.push_back(num);
            }
            else
                m[num]++;
        }
        backtrace(0);
        return res;
    }

    void backtrace(int idx)
    {
        if (sum == target)
            res.push_back(path);
        if (sum >= target || idx == candidates.size())
            return;
        // 没有candidates[idx]的子集
        backtrace(idx + 1);
        // 有candidates[idx]的子集
        for (int j = 0; j < m[candidates[idx]]; j++)
        {
            path.push_back(candidates[idx]);
            sum += candidates[idx];
            backtrace(idx + 1);
        }
        for (int j = 0; j < m[candidates[idx]]; j++)
        {
            path.pop_back();
            sum -= candidates[idx];
        }
    }
};

int main()
{
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    Solution s;
    s.combinationSum2(candidates, target);
}