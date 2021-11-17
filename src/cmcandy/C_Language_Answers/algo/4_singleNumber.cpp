#include <iostream>
using namespace ::std;

int singleNumber(int *nums, int len)
{
    int bitSums[32] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < 32; j++)
        {
            bitSums[j] += (nums[i] >> (31 - j)) & 1;
        }
    }
    int result = 0;
    for (int i = 0; i < 32; i++)
    {   
        //这里%3是因为告诉你了其他数字都出现了三次。。。。。
        result = (result << 1) + bitSums[i] % 3;
    }

    return result;
}
int main()
{
    int arr[7] = {0, 1, 0, 1, 0, 1, 100};
    cout<<singleNumber(arr, 7);
}