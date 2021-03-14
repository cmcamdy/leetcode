#include <iostream>
#include <string>
#include <vector>
using namespace ::std;
//暴力法，超时
class Solution
{
public:
    int knightDialer(int n)
    {
        if (n == 1)
            return 10;
        int sum = 0;
        for (int i = 0; i < 10; i++)
        {
            sum += help(i, n - 1);
        }
        return sum;
    }
    int help(int place, int n)
    {
        //1=6、8
        //2=7、9
        //3=4、8
        //4=3、9、0
        //5=不可能跳到，不用考虑
        //6=1、7、0
        //7=2、6
        //8=1、3
        //9=2、4
        //0=4、6
        if (n == 0)
            return 1;
        if (place == 5)
            return 0;
        int sum = 0;
        switch (place)
        {
        case 1:
            sum += help(6, n - 1);
            sum += help(8, n - 1);
            break;
        case 2:
            sum += help(7, n - 1);
            sum += help(9, n - 1);
            break;
        case 3:
            sum += help(4, n - 1);
            sum += help(8, n - 1);
            break;
        case 4:
            sum += help(3, n - 1);
            sum += help(9, n - 1);
            sum += help(0, n - 1);
            break;
        case 5:
            break;
        case 6:
            sum += help(1, n - 1);
            sum += help(7, n - 1);
            sum += help(0, n - 1);
            break;
        case 7:
            sum += help(2, n - 1);
            sum += help(6, n - 1);
            break;
        case 8:
            sum += help(1, n - 1);
            sum += help(3, n - 1);
            break;
        case 9:
            sum += help(2, n - 1);
            sum += help(4, n - 1);
            break;
        case 0:
            sum += help(4, n - 1);
            sum += help(6, n - 1);
            break;
        default:
            break;
        }
        return sum;
    }
};