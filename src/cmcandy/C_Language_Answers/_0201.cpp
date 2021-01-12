#include <iostream>
using namespace ::std;

class Solution
{
public:
    int rangeBitwiseAnd(int m, int n)
    {
        //注意题目是要求[m,n]所有数字的与，即他们的求共同前缀
        int mask = 1 << 30;
        int res = 0;
        while (mask > 0 && ((mask & m) == (mask & n)))
        {
            res |= m & mask;
            mask >>= 1;
        }
        return res;
    }
};

int main()
{
    cout << (7 & 5) << endl;
    return 0;
}
