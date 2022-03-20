#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace ::std;

class Solution
{
public:
    string repeatLimitedString(string s, int repeatLimit)
    {
        vector<int> nums(26, 0);
        string res;
        for (int i = 0; i < s.size(); i++)
        {
            nums[s[i] - 'a']++;
        }
        int last = -1;
        for (int i = 25; i >= 0; i--)
        {
            if (nums[i] != 0)
                if (last != -1)
                {
                    while (nums[last] > 0 && nums[i] > 0)
                    {
                        res.push_back((char)('a' + i));
                        for (int j = 0; j < min(nums[last],repeatLimit); j++)
                        {
                            res.push_back((char)('a' + last));
                        }
                        nums[last]-=repeatLimit;
                        nums[i]--;
                    }
                    if (nums[last] == 0)
                        last = -1;
                }
            // 如果last还有，则找下一个，这里就不体现，如果i还有则继续装
            if (repeatLimit >= nums[i])
            {
                for (int j = 0; j < nums[i]; j++)
                {
                    res.push_back((char)('a' + i));
                }
            }
            else
            {
                for (int j = 0; j < repeatLimit; j++)
                {
                    res.push_back((char)('a' + i));
                }
                last = i;
                nums[i] -= repeatLimit;
            }
        }
        return res;
    }
};
int main()
{
    Solution s;
    cout << s.repeatLimitedString("robnsdvpuxbapuqgopqvxdrchivlifeepy", 2) << endl;
    cout << s.repeatLimitedString("cczazcc", 3) << endl;
}