#include <iostream>
#include <vector>
#include <algorithm>
using namespace ::std;
class Solution
{
public:
    int sumOddLengthSubarrays(vector<int> &arr)
    {
        int len = arr.size();
        int l = 1;
        int res = 0;
        while (l <= len)
        {
            int sum = 0;
            for (int i = 0; i < l; i++)
            {
                sum += arr[i];
            }
            res += sum;
            for (int i = 1; i <= len - l; i++)
            {
                sum = sum - arr[i - 1] + arr[i + l - 1];
                res += sum;
            }
            l += 2;
        }
        return res;
    }
};