#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace ::std;
class Solution
{
public:
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
    {
        map<int, int> m;
        for (auto &ele : arr1)
        {
            if (m.count(ele) < 1)
                m[ele] = 1;
            else
                m[ele]++;
        }
        int index = 0;
        for (auto &ele : arr2)
        {

            for (int tmp = index; tmp < index + m[ele]; tmp++)
            {
                arr1[tmp] = ele;
            }
            index += m[ele];
            m[ele] = 0;
        }
        map<int, int>::iterator iter;
        iter = m.begin();
        while (iter != m.end())
        {
            for (int tmp = index; tmp < index + iter->second; tmp++)
            {
                arr1[tmp] = iter->first;
            }
            index += iter->second;
            iter++;
        }
        return arr1;
    }
};

int main()
{
    Solution s;
    vector<int> arr1 = {2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19}, arr2 = {2, 1, 4, 3, 9, 6};
    s.relativeSortArray(arr1, arr2);
}