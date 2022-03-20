#include <iostream>
#include <unordered_map>
#include <vector>
using namespace ::std;

class Solution
{
public:
    int checkLen(vector<int> &nums1, vector<int> &nums2, int index1, int index2)
    {
        int i1 = index1, i2 = index2;
        while (i1 < nums1.size() && i2 < nums2.size() && nums1[i1] == nums2[i2])
        {
            i1++;
            i2++;
        }
        return i1 - index1;
    }
    int findLength(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, vector<int>> m;
        for (int i = 0; i < nums2.size(); i++)
        {
            if (m.find(nums2[i]) == m.end())
            {
                m[nums2[i]] = vector<int>{i};
            }
            else
            {
                m[nums2[i]].push_back(i);
            }
        }
        int maxlen = 0;
        for (int i = 0; i < nums1.size(); i++)
        {
            if (m.find(nums1[i]) != m.end())
            {
                for (int j : m[nums1[i]])
                {
                    maxlen = max(maxlen, checkLen(nums1, nums2, i, j));
                    if (maxlen + i == nums1.size())
                        return maxlen;
                }
            }
        }
        return maxlen;
    }
};

class Solution2
{
public:
    int findLength(vector<int> &A, vector<int> &B)
    {
        return A.size() <= B.size() ? helper(A, B) : helper(B, A);
    }
    //窗口滑动的重叠过程可以分为三个过程：
    // 1、下面子串进入，开始重叠的过程
    // 2、上下两子串完全重叠，中间过程
    // 3、下面的子串开始离开，重叠区域减少，离开过程
    int helper(vector<int> &A, vector<int> &B)
    {
        int na = A.size();
        int nb = B.size();
        int ret = 0;
        //进入时候的处理
        for (int len = 1; len <= na; len++)
        {
            int tmplen = maxlen(A, 0, B, nb - len, len);
            ret = max(ret, tmplen);
        }
        //中间过程的处理
        for (int indexb = nb; indexb - na >= 0; indexb--)
        {
            int tmplen = maxlen(A, 0, B, indexb - na, na);
            ret = max(ret, tmplen);
        }
        //出去时的处理
        for (int len = na; len > 0; len--)
        {
            int tmplen = maxlen(A, na - len, B, 0, len);
            ret = max(ret, tmplen);
        }
        return ret;
    }
    int maxlen(vector<int> &A, int indexa, vector<int> &B, int indexb, int len)
    {
        int ret = 0;
        int countnum = 0;
        for (int i = 0; i < len; i++)
        {
            if (A[indexa + i] == B[indexb + i])
            {
                countnum++;
            }
            else if (countnum > 0)
            {
                ret = max(ret, countnum);
                countnum = 0;
            }
        }
        return max(ret, countnum);
    }
};
int main()
{

    Solution s;
    vector<int> nums1 = {0, 0, 0, 0, 0};
    vector<int> nums2 = {0, 0, 0, 0, 0};

    // vector<int> nums1 = {1, 2, 3, 2, 1};
    // vector<int> nums2 = {3, 2, 1, 4, 7};

    cout << s.findLength(nums1, nums2);
}
