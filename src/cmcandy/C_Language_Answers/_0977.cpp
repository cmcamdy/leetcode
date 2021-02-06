#include <iostream>
#include <string>
#include <vector>
using namespace ::std;
class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        int len = nums.size();
        int left, right;
        vector<int> res;
        //找到绝对值最小的数
        if (nums[len - 1] < 0)
        {
            left = len - 1;
            right = len;
        }
        else
        {
            for (int i = 0; i < len; i++)
            {
                if (nums[i] >= 0)
                {
                    left = i - 1;
                    right = i;
                    break;
                }
            }
        }
        //用双指针双向走
        while (left >= 0 || right < len)
        {
            if (left < 0)
            {
                //左侧无，直接右侧
                res.push_back(nums[right] * nums[right++]);
            }
            else if (right >= len)
            {
                //右侧无，直接左侧
                res.push_back(nums[left] * nums[left--]);
            }
            else
            {
                //左右都有，则比较,找绝对值大的那个
                res.push_back(abs(nums[left]) < nums[right] ? nums[left] * nums[left--] : nums[right] * nums[right++]);
            }
        }
        return res;
    }
};
int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> nums{-5, -3, -2, -1};
    s.sortedSquares(nums);
    return 0;
}
