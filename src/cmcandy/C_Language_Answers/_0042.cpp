#include <iostream>
#include <string>
#include <vector>

using namespace ::std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        //双指针
        int len = height.size();
        if (len < 3)
            return 0;
        //左边最高、右边最高
        int left = 0, right = len - 1;
        int li = 0, ri = right; //左右指针
        int sum = 0;
        int jud = 0; //0=li++ 1=ri--
        //如果右边比较埃，则右边先开始
        if (height[left] > height[right])
            jud = 1;
        while (li < ri)
        {
            //若当前列<min(l,r),加上差值
            //若当前列至少比其中一个大，则替换小的
            if (jud == 0)
            {
                if (height[++li] > height[left])
                {
                    left = li;
                    //如果是比右边高，则换个方向
                    if (height[li] > height[right])
                        jud = 1;
                }
                else
                {
                    sum += height[left] - height[li];
                }
            }
            else
            {
                if (height[--ri] > height[right])
                {
                    right = ri;
                    //如果是比左边高，则换个方向
                    if (height[ri] > height[left])
                        jud = 0;
                }
                else
                {
                    sum += height[right] - height[ri];
                }
            }
        }
        return sum;
    }
};