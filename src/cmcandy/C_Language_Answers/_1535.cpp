#include <iostream>
#include <vector>
using namespace ::std;
class Solution
{
public:
    int getWinner(vector<int> &arr, int k)
    {
        //只需要找出k个比他小即可（其后面连续k个）
        //如果找到底了，那么有一点，就是目前arr[tmp]的值一定是最大值，那么肯定是答案
        int len = arr.size();
        int tmp = 0;
        int win = 0;
        for (int i = 0; i < len; i++)
        {
            if (arr[tmp] > arr[i])
            {
                win++;
            }
            else if (arr[tmp] < arr[i])
            {
                tmp = i;
                win = 1;
            }
            if (win == k)
                return arr[tmp];
        }
        return arr[tmp];
    }
};