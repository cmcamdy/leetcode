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
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        this->candidates = candidates;
        this->target = target;
        this->sum = 0;
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
        int tmpSum = sum;
        for (int j = 0; j < (target - tmpSum) / candidates[idx] + 1; j++)
        {
            path.push_back(candidates[idx]);
            sum += candidates[idx];
            backtrace(idx + 1);
        }
        for (int j = 0; j < (target - tmpSum) / candidates[idx] + 1; j++)
        {
            path.pop_back();
            sum -= candidates[idx];
        }
    }
};

int main()
{
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    Solution s;
    s.combinationSum(candidates, target);
}