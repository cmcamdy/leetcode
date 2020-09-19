#include <iostream>
#include <vector>

using namespace::std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        if (n == 0)
            return;
        if (m == 0)
        {
            nums1 = nums2;
            return;
        }
        int t1 = m - 1, t2 = n - 1, t3 = m + n - 1;
        while (t2 >= 0)
        {
            if (t1 >= 0 && nums2[t2] < nums1[t1])
            {
                nums1[t3--] = nums1[t1];
                nums1[t1--] = 0;
            }
            else
            {
                nums1[t3--] = nums2[t2];
                t2--;
            }
        }
    }
};