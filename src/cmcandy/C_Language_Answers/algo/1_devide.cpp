#include <iostream>
#include <limits.h>
using namespace ::std;

int divideCore(int, int);
int devide(int, int);

int devide(int dividend, int divisor)
{
    //最小的int数，这是边界情况
    if (dividend == 0x80000000 && divisor == -1)
    {
        // return Integer.Max_VALUE;
        return INT_MAX;
    }
    //这里是统计负数的个数如果只有一个的话就变为-1，结果就多个符号，如果偶数，负负得正
    int negative = 2;
    if (dividend > 0)
    {
        negative--;
        dividend = -dividend;
    }
    if (divisor > 0)
    {
        negative--;
        divisor = -divisor;
    }
    //因此这里输入的是俩负数
    int result = divideCore(dividend, divisor);
    return negative == 1 ? -result : result;
}
int divideCore(int dividend, int divisor)
{
    int result = 0;
    // dividend <= divisor这句的意思其实是想表明dividend>divisor，但是由于俩都是负数，就变成<=
    while (dividend <= divisor)
    {
        int value = divisor;
        int quotient = 1;
        //这里的思路就是每次搞掉最高位那一个数
        while (value >= 0xc0000000 && dividend <= value + value)
        {
            quotient += quotient;
            value += value;
        }
        result += quotient;
        dividend -= value;
    }
    return result;
}

int main()
{
    cout << devide(7, 2);
}
