#include <iostream>
#include <vector>

using namespace ::std;

class NumArray
{
public:
    vector<int> f;

public:
    NumArray(vector<int> &nums)
    {
        //用一个数组记录前N个总和即可
        int len = nums.size();
        if (len > 0)
        {
            f.push_back(nums[0]);
            for (int i = 1; i < len; i++)
            {
                f.push_back(nums[i] + f[i - 1]);
            }
        }
    }

    int sumRange(int i, int j)
    {
        if (f.size() == 0)
            return 0;
        return i == 0 ? f[j] : f[j] - f[i - 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */