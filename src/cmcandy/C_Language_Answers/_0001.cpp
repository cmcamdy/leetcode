#include <iostream>
#include <vector>
#include <math.h>
#include <map>
#include <unordered_set>
using namespace ::std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        map<int, int> m;
        int len = nums.size();
        vector<int> res(2, 0);
        int tmp = 0;
        for (int i = 0; i < len; i++)
        {
            tmp = nums[i];
            if (m.count(target - tmp) > 0)
            {
                res[0] = m[target - tmp];
                res[1] = i;
                return res;
            }
            else
            {
                m[nums[i]] = i;
            }
        }
        return res;
    }
};
int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> nums = {3, 2, 4};
    vector<int> res =  s.twoSum(nums, 6);
    cout<<res[0]<<endl;
    return 0;
}
