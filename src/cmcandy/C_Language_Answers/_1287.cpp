#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace ::std;

class Solution
{
public:
    int findSpecialInteger(vector<int> &arr)
    {
        map<int, int> m;
        int len = arr.size();
        int quad = len / 4;
        for (int i = 0; i < len; i++)
        {
            if (m.count(arr[i]) < 1)
            {
                m[arr[i]] = 1;
            }
            else
                m[arr[i]]++;
            if (m[arr[i]] > quad)
                return arr[i];
        }
        return -1;
    }
};