#include <iostream>
#include <stack>
#include <vector>
#include <map>
using namespace ::std;
class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        int len1 = nums1.size();
        int len2 = nums2.size();

        map<int, int> m;
        stack<int> s;
        vector<int> res(len1, -1);
        //用map记录一下每个数的位置，便于后面寻找
        for (int i = 0; i < len1; i++)
        {
            m[nums1[i]] = i;
        }
        s.push(nums2[0]);
        for (int i = 1; i < len2; i++)
        {
            //单调栈思想
            while ((!s.empty()) && s.top() < nums2[i])
            {
                if (m.find(s.top()) != m.end())
                {
                    res[m[s.top()]] = nums2[i];
                }
                s.pop();
            }
            s.push(nums2[i]);
        }
        return res;
    }
};
int main(int argc, char const *argv[])
{
    Solution s;

    vector<int> nums1{4, 1, 2};
    vector<int> nums2{1, 3, 4, 2};
    vector<int> res = s.nextGreaterElement(nums1, nums2);
    return 0;
}
