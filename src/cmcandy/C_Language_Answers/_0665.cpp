#include <iostream>
#include <string>
#include <vector>
using namespace ::std;

class Solution
{
public:
    bool checkPossibility(vector<int> &nums)
    {
        int jud = 2;
        int len = nums.size();
        int i = 1;
        while (i < len && jud > 0)
        {
            if (nums[i] < nums[i - 1])
            {
                if (i > 1 && nums[i - 2] > nums[i])
                    nums[i] = nums[i - 1];
                else
                    nums[i - 1] = nums[i];
                jud--;
            }
            i++;
        }
        return jud > 0 ? true : false;
    }
};