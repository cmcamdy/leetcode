#include <iostream>
#include <vector>
#include <map>
using namespace ::std;
class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int len = nums.size();
        if (len == 1)
            return nums[0];
        if (nums[0] != nums[1])
            return nums[0];
        if (nums[len - 1] != nums[len - 2])
            return nums[len - 1];
        int left = 0, right = (len - 1) / 2;
        while (left < right)
        {
            int mid = (left + right) / 2 * 2;
            if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
                return nums[mid];
            else if (nums[mid] != nums[mid - 1])
                left = mid / 2;
            else
                right = mid / 2;
        }
        return -1;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {3, 3, 7, 7, 10, 11, 11};
    // vector<int> nums={1,1,3,3,4,4,2,8,8};
    cout << s.singleNonDuplicate(nums);
}