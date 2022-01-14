#include <iostream>
#include <random>
using namespace std;
class Solution
{

private:
    // 随机数：https://blog.csdn.net/qq_42780289/article/details/91348748
    mt19937 gen;
    uniform_int_distribution<int> dis;
    vector<int> pre;

public:
    Solution(vector<int> &w) : gen(random_device{}()), dis(1, accumulate(w.begin(), w.end(), 0))
    {
        partial_sum(w.begin(), w.end(), back_inserter(pre));
    }

    int pickIndex()
    {
        int x = dis(gen);
        return lower_bound(pre.begin(), pre.end(), x) - pre.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */