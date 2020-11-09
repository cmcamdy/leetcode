#include <iostream>
#include <string>
#include <vector>
using namespace ::std;

class Solution
{
public:
    vector<int> shortestToChar(string S, char C)
    {
        int len = S.size();
        vector<int> nums(len, 10000);
        int tag = 0;
        for (int i = 0; i < len; i++)
        {
            //  每找到一个，就向左推，直到上一个tag，或者距离大于nums数组
            if (S[i] == C)
            {
                for (int j = i; j >= tag; j--)
                {
                    if (nums[j] > i - j)
                    {
                        nums[j] = i - j;
                    }
                    else
                        //遇到了比他小的则说明左侧有更近的，故不需要再继续
                        break;
                }
                tag = i;
            }
            else if (tag > 0 || S[0] == C)
            {
                //向右推进
                nums[i] = i - tag;
            }
        }
        return nums;
    }
};