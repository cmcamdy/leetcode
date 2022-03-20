#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace ::std;

// class Solution
// {
// public:
//     long long goodTriplets(vector<int> &nums1, vector<int> &nums2)
//     {
//         unordered_map<int, int> m1, m2, m3, m4;
//         // unordered_map<int,int>m2,m3;

//         // m3,m4用于记录中间=j的时候的成立的数目
//         // init map
//         for (int i = 0; i < nums1.size(); i++)
//         {
//             m1[nums1[i]] = i;
//             m2[nums2[i]] = i;
//         }
//         long long count = 0;
//         // find good groups
//         for (int i = 0; i < nums1.size(); i++)
//         {
//             if (m2[nums1[i]] <= i)
//             {
//             for (int j = i + 1; j < nums1.size(); j++)
//             {
//                 if (m2[nums1[i]] < m2[nums1[j]])
//                 {
//                     if (!m3.count(nums1[j]))
//                     {
//                         int tmp = 0;
//                         if (j >= m2[nums1[j]])
//                         {
//                             for (int k = j + 1; k < nums1.size(); k++)
//                             {
//                                 if (m2[nums1[j]] < m2[nums1[k]])
//                                 {
//                                     tmp++;
//                                 }
//                             }
//                         }
//                         else
//                         {
//                             for (int k = m2[nums1[j]] + 1; k < nums1.size(); k++)
//                             {
//                                 if (j < m1[nums2[k]])
//                                 {
//                                     tmp++;
//                                 }
//                             }
//                         }
//                         m3[nums1[j]] = tmp;
//                     }
//                     count += m3[nums1[j]];
//                 }
//             }
//             }
//             else
//             {
//                 for (int j = m2[nums1[i]] + 1; j < nums1.size(); j++)
//                 {
//                     if (i < m1[nums2[j]])
//                     {
//                         if (!m3.count(nums2[j]))
//                         {
//                             int tmp = 0;
//                             if (j <= m1[nums2[j]])
//                             {
//                                 for (int k = m1[nums2[j]] + 1; k < nums1.size(); k++)
//                                 {
//                                     if (j < m2[nums1[k]])
//                                     {
//                                         tmp++;
//                                     }
//                                 }
//                             }
//                             else
//                             {
//                                 for (int k = j + 1; k < nums1.size(); k++)
//                                 {
//                                     if (m1[nums2[j]] < m1[nums2[k]])
//                                     {
//                                         tmp++;
//                                     }
//                                 }
//                             }
//                             m3[nums2[j]] = tmp;
//                         }
//                         count += m3[nums2[j]];
//                     }
//                 }
//             }
//         }
//         return count;
//     }
// };


using LL = long long;
struct BIT{
    int n;
    vector<LL> v;
    BIT(int n) : n(n), v(n){
    }
		
    void add(int x, LL y) {
				// 这里(x & -x)实际上是在计算lowbit，下面的也是
        for (x += 1; x <= n; x += x & -x) v[x - 1] += y;
    }
    LL sum(int x) {
        LL res = 0;
        for (x += 1; x; x -= x & -x) res += v[x - 1];
        return res;
    }
};
class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> p(n), a(n);
        // 这是俩hashmap
        
        // 数组1中的元素的下标
        for (int i = 0; i < n; i += 1) p[nums1[i]] = i;
        // 数组2中元素在数组1中的位置
        for (int i = 0; i < n; i += 1) a[i] = p[nums2[i]];
        vector<LL> bit(n);
        // 树状数组
        BIT s(n), s2(n);
        LL ans = 0;
        for (int i = 0; i < n; i += 1) {
            ans += s2.sum(a[i]);
            s2.add(a[i], s.sum(a[i]));
            s.add(a[i], 1);
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> nums1 = {13, 14, 10, 2, 12, 3, 9, 11, 15, 8, 4, 7, 0, 6, 5, 1}, nums2 = {8, 7, 9, 5, 6, 14, 15, 10, 2, 11, 4, 13, 3, 12, 1, 0};
    cout << s.goodTriplets(nums1, nums2);
}



