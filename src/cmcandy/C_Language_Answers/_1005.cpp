#include <iostream>
#include <string>
#include <vector>
using namespace ::std;
class Solution
{
public:
    int largestSumAfterKNegations(vector<int> &A, int K)
    {
        vector<int> nums(201, 0);
        for (int i = 0; i < A.size(); i++)
        {
            nums[A[i] + 100]++;
        }
        int index = 0;
        while (K-- > 0)
        {
            // 找到第一个不为0的数
            while (nums[index] == 0)
                index++;
            nums[index]--;
            nums[200 - index]++;
            if (index > 100)
            {
                K = K % 2;           //降低循环次数
                index = 200 - index; //降低寻找次数
            }
        }
        int sum = 0;
        for (int i = 0; i < 201; i++)
        {
            if (nums[i] != 0)
                sum += nums[i] * (i - 100);
        }
        return sum;
    }
};