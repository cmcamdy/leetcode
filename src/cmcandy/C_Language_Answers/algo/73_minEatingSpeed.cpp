#include <iostream>
#include <vector>
#include <algorithm>
using namespace ::std;

class Solution
{
public:
    int countTime(vector<int> &piles, int k)
    {
        int t = 0;
        for (auto &p : piles)
        {
            t += p / k + (p % k > 0);
        }
        return t;
    }
    int minEatingSpeed(vector<int> &piles, int h)
    {
        // 最大，最小胃口
        int left = 1, right = *max_element(piles.begin(), piles.end());
        while (left <= right)
        {
            int mid = left + ((right - left) >> 1);
            if (countTime(piles, mid) <= h)
            {
                if (mid == 1 || countTime(piles, mid - 1) > h)
                {
                    return mid;
                }
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return -1;
    }
};
int main()
{
    Solution s;
    vector<int> piles = {30, 11, 23, 4, 20};
    cout << s.minEatingSpeed(piles, 5);
}