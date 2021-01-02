#include <iostream>
#include <string>
#include <vector>

using namespace ::std;

class Solution
{
public:
    int addDigits(int num)
    {
        int tmp = 0;
        while (num > 0)
        {
            tmp += num % 10;
            num = num / 10;
        }
        if (tmp >= 10)
            return addDigits(tmp);
        else
            return tmp;
    }
    
    int addDigits2(int num)
    {
        //将余数范围扩充到0~9
        return (num - 1) % 9 + 1;
    }
};