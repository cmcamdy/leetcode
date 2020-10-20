#include <iostream>
#include <string>
#include <vector>

using namespace ::std;
class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {

        int len = nums.size();
        if (len == 0 || (len == 1 && nums[0] != 1))
            return 1;
        else if (len == 1 && nums[0] == 1)
            return 2;
        int i = 0;
        while (i < len)
        {
            cout << nums[0] << nums[1] << nums[2]<<nums[3] << endl;
            if (nums[i] != i)
            {
                if (nums[i] >= len || nums[i] <= 0)
                {
                    nums[i] = 0;
                    i++;
                }
                else if (nums[nums[i]] != nums[i])
                {
                    int tmp = nums[nums[i]];
                    nums[nums[i]] = nums[i];
                    nums[i] = tmp;
                }else i++;
            }
            else
                i++;
        }
        for (int j = 1; j < len; j++)
        {
            if (nums[j] == 0)
                return j;
        }
        return i;
    }
};
int main()
{
    Solution s;
    int a[] = { 1, 1};
    vector<int> v(a, a + 4);
    s.firstMissingPositive(v);
}