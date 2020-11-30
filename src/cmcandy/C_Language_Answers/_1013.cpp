#include <iostream>
#include <string>
#include <vector>
using namespace ::std;
class Solution
{
public:
    bool canThreePartsEqualSum(vector<int> &A)
    {

        //双指针即可
        int len = A.size();
        int left = 0, right = len - 1;
        int lsum = A[left], rsum = A[len - 1];
        int sum = 0;
        for (int i = 0; i < len; i++)
        {
            sum += A[i];
        }
        if (sum % 3 != 0)
            return false;
        sum = sum / 3;
        while (left < right)
        {
            //如果左右不等，则继续前移
            if (lsum != sum)
            {
                lsum += A[++left];
            }
            if (rsum != sum)
            {
                rsum += A[--right];
            }
            if (rsum == lsum && lsum == sum)
                break;
        }
        return left + 1 < right && lsum == rsum ? true : false;
    }
};