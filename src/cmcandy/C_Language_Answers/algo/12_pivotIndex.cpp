#include <iostream>
#include <vector>
using namespace ::std;
class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        int len = nums.size();
        int suml = 0, sumr = 0;

        for (int i = 1; i < len; i++)
        {
            sumr += nums[i];
        }
        int i = 0;
        for (i = 0; i < len - 1; i++)
        {
            if (suml == sumr)
                return i;
            suml += nums[i];
            sumr -= nums[i + 1];
        }
        return suml == sumr ? len - 1 : -1;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {-1, -1, -1, 1, 1, -1};
    cout << s.pivotIndex(nums);
}