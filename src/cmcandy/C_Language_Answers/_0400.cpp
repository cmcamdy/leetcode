#include <iostream>
#include <cmath>
using namespace ::std;
class Solution
{
public:
    int findNthDigit(int n)
    {
        int digit = 1, res = 0;
        long tmp = 9;
        while (n > tmp)
        {
            n -= tmp;
            tmp = 9 * pow(10, digit) * (digit + 1);
            digit++;
        }
        // 拿到了第几个数的第几位
        int numB = (n - 1) / digit, numS = (n - 1) % digit;
        return (int((pow(10, digit - 1) + numB)) % (int(pow(10, digit - numS)))) / pow(10, digit - numS - 1);
    }
};
int main()
{
    Solution s;
    cout<<s.findNthDigit(1000000000);
    // for (int i = 0; i < 1200; i++)
    // {
    //     // cout<<i+1<<"="<<s.findNthDigit(i+1)<<endl;
    //     cout << s.findNthDigit(i + 1) << endl;
    // }
}