#include <iostream>
#include <stack>
#include <vector>
#include <map>
using namespace ::std;

class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        //遍历两遍还找不到就是真没有
        int len = nums.size();
        map<int, int> m;
        stack<int> s;
        vector<int> res(len, -1);
        //用map记录一下每个数的位置，便于后面寻找
        for (int i = 0; i < len; i++)
        {
            m[nums[i]] = i;
        }

        for (int j = 0; j < 2; j++)
        {
            for (int i = 0; i < len; i++)
            {
                while ((!s.empty()) && s.top() < nums[i])
                {
                    if (m.find(s.top()) != m.end())
                    {
                        res[m[s.top()]] = nums[i];
                    }
                    s.pop();
                }
                s.push(nums[i]);
            }
        }
        return res;
    }
};
int main(int argc, char const *argv[])
{
    Solution s;

    vector<int> nums{1,2,1};
    vector<int> res = s.nextGreaterElements(nums);
    return 0;
}
