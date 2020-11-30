#include <iostream>
#include <string>
#include <vector>
using namespace ::std;
class Solution
{
public:
    int numPairsDivisibleBy60(vector<int> &time)
    {
        //利用数组来记录满足要求的数字
        vector<int> record(60, 0);
        int tmp, sum = 0;
        int len = time.size();
        for (int i = 0; i < len; i++)
        {
            tmp = time[i] % 60;
            if (tmp == 0)
                sum += record[0];
            else
            {
                sum += record[60 - tmp];
            }
            record[tmp]++;
        }
        return sum;
    }
};