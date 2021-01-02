#include <iostream>
#include <vector>

using namespace ::std;
class Solution
{
public:
    int monotoneIncreasingDigits(int N)
    {
        vector<int> res;
        //1.高位先取，如果满足递增则一直去下去
        //2.如果不满足，那么上一位--
        //  3.如果上一位-- 后，依然满足递增，则后面全9即可
        //  4.如果不满足，再上一位--，循环判断，直到最高位
        string digit = to_string(N);
        int len = digit.size();
        if (len < 2)
            return N;
        int i = 1;
        int flag = 0;
        while (i > 0 && i < len)
        {
            if (digit[i] >= digit[i - 1])
            {
                //如果是调整过且符合要求，直接break
                if (flag == 1)
                    break;
                //如果没调整，那就老老实实i++
                i++;
            }
            else if (digit[i] < digit[i - 1])
            {
                //上一位--，且调整标志置为1，一旦通过就通过
                digit[--i]--;
                flag = 1;
            }
        }
        //剩下的位全部置为9即可
        for (i; i < len - 1; i++)
        {
            digit[i + 1] = '9';
        }
        return stoi(digit);
    }
};