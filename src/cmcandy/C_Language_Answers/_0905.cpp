#include <iostream>
#include <string>
#include <vector>
using namespace ::std;
class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &A)
    {
        //双指针
        int len = A.size();
        int right = len - 1, left = 0;

        while (left < right)
        {
            if (A[left] % 2 == 1)
            {
                while (A[right] % 2 == 1 && right > 0)
                    right--;
                if (left < right)
                    swap(A[right], A[left]);
            }
            left++;
        }

        return A;
    }
};