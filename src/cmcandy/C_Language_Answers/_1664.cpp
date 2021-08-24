#include <iostream>
#include <vector>
using namespace ::std;

class Solution
{
public:
    int waysToMakeFair(vector<int> &nums)
    {
        int odd_sum = 0, even_sum = 0;
        int len = nums.size();
        int res = 0;
        int n_odd_sum = 0, n_even_sum = 0;
        //奇偶元素下标元素求和
        for (int i = 0; i < len; i++)
        {
            if (i % 2 == 0)
                even_sum += nums[i];
            else
                odd_sum += nums[i];
        }

        for (int i = 0; i < len; i++)
        {
            if (i % 2 == 0)
            {
                //偶数位和-=
                even_sum -= nums[i];
                if (n_odd_sum + even_sum == n_even_sum + odd_sum)
                    res++;
                n_even_sum += nums[i];
            }
            else
            {
                //奇数位和-=
                odd_sum -= nums[i];
                if (n_odd_sum + even_sum == n_even_sum + odd_sum)
                    res++;
                n_odd_sum += nums[i];
            }
        }
        return res;
    }
};