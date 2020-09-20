#include <iostream>
#include <vector>

using namespace ::std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        m--;
        n--;
        while (n >= 0)
            nums1[n + m + 2] = m >= 0 && nums2[n] < nums1[m] ? nums1[m--] : nums2[n--];
    }
};