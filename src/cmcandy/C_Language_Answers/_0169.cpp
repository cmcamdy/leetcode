
#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace ::std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        map<int, int> m;
        map<int, int>::iterator it;
        int len = nums.size();
        for (int i = 0; i < len; i++)
            m[nums[i]] = m.find(nums[i]) == m.end() ? 1 : m.find(nums[i])->second + 1;
        it = m.begin();
        while (it != m.end())
        {

            if (it->second > len / 2)
            {
                return it->first;
            }
            it++;
        }
        return -1;
    }
};
int main()
{
    Solution s;
    int a[] = {2, 2, 1, 1, 1, 2, 2};
    vector<int> v(a, a + 6);
    s.majorityElement(v);
}