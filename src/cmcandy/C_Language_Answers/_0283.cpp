#include <iostream>
#include <vector>

using namespace ::std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int len = nums.size();
        int i = 0;
        while (i < len && nums[i] != 0)
            i++; //移动到第一个0元素的位置
        int fast = i;   
        for (; i < len; i++)
        {
            if (nums[i] != 0)
            {
                nums[fast++] = nums[i];
                nums[i] = 0;
            }
        }
    }
};