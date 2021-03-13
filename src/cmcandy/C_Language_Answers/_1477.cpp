#include <iostream>
#include <vector>
#include <algorithm>
using namespace ::std;

class Solution
{
public:
    int minSumOfLengths(vector<int> &arr, int target)
    {
        //滑动窗口算法
        int len = arr.size();
        if (len == 1)
            return -1;
        //在数组两侧用两个滑动窗口
        //其中left1和right2取值界限，
        int left1 = len - 1, left2 = len - 1, right1 = 0, right2 = 0;
        // 用于判断什么时候该停了
        int border1 = right1, border2 = left1;
        //这俩是记录最小值用的
        int mr = len, ml = len;
        int sumr = arr[0];
        int suml = arr[len - 1];
        //true=左动
        int lturn = 1,rturn=1,turn=1;

        while (left1 > border1 && right2 < border2)
        {   
            if(rturn==0&&lturn==1)  turn=0;
            else if(rturn==1&&lturn==0)  turn=1;
            else if(rturn==0&&lturn==0)  break;
            // else if(lturn==1) turn=0;

            //如果mr>=ml 动右边
            if (turn==1)
            {
                if (sumr < target)
                {
                    right2++;
                    sumr += arr[right2];
                }
                else if (sumr >= target)
                {
                    if (sumr == target)
                    {
                        mr = min(mr, right2 - right1 + 1);
                        border1 = right2;
                        turn=0;
                    }
                    sumr -= arr[right1];
                    
                    right1++;
                    if (right2 < right1)
                    {
                        right2 = right1;
                        sumr += arr[right1];
                    }
                }
                if(right2>border2-1||right1>border2-1){
                    //触碰到边界
                    rturn=0;
                    right1 = border1;
                    right2 = border1;
                }
            }
            //如果mr<ml 动左边
            else if(turn == 0){
                if (suml < target)
                {
                    
                    left1--;
                    suml += arr[left1];
                }
                else if (suml >= target)
                {
                    if (suml == target)
                    {
                        ml = min(ml, left2 - left1 + 1);
                        border2 = left1;
                        turn=1;
                    }
                    suml -= arr[left2];
                    
                    left2--;
                    if (left2 < left1)
                    {
                        left1 = left2;
                        suml += arr[left1];
                    }
                }
                if(left1<border1+1||left2<border1+1){
                    //触碰到边界
                    lturn=0;
                    left1 = border2;
                    left2 = border2;
                }
            }
        }
        // return m2 < len ? m1 + m2 : -1;
        return border2>border1&&ml<len&&mr<len?mr+ml:-1;
    }
};
int main(int argc, char const *argv[])
{
    Solution s;

    // vector<int> arr{3,2,2,4,3};//3
    // vector<int> arr{1,1,1,2,2,2,4,4};//6
    // vector<int> arr{2, 1, 3, 3, 2, 3, 1};
    // vector<int> arr{3,1,1,1,5,1,2,1};//3
    // vector<int> arr{1,2,2,3,2,6,7,2,1,4,8};//5
    // vector<int> arr{31,1,1,18,15,3,15,14};//33
    vector<int> arr{2,2,4,4,4,4,4,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};//20
    s.minSumOfLengths(arr, 20);
    return 0;
}
