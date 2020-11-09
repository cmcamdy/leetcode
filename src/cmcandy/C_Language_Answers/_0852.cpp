#include <iostream>
#include <string>
#include <vector>
using namespace ::std;
class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        //i有的话必定只有一个，没有就没有
        int len = arr.size();
        int peak = -1;
        for (int i = 1; i < len; i++)
        {
            if (peak == -1)
            {
                if (arr[i] < arr[i - 1])
                    peak = i - 1;
            }
            else
            {
                if (arr[i] > arr[i - 1])
                    return -1;
            }
        }
        return peak;
    }
};