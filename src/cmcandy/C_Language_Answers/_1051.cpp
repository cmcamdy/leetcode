#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace ::std;
class Solution
{
public:
    int heightChecker(vector<int> &heights)
    {
        int size = heights.size();
        vector<int> vec(heights);
        sort(vec.begin(), vec.end());
        int i, count = 0;
        for (i = 0; i < size; i++)
            if (heights[i] != vec[i])
                ++count;
        return count;
    }
};