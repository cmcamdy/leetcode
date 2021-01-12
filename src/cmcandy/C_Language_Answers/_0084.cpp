#include <iostream>
#include <vector>
#include <stack>
using namespace ::std;
class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {

        //栈的思想

        stack<int> s;
        //哨兵1、2号
        heights.insert(heights.begin(), 0);
        heights.push_back(0);
        s.push(0);
        int len = heights.size();
        int area = 0;
        int width = 0;

        for (int i = 0; i < len; i++)
        {
            cout << heights[i] << " ";
        }
        cout << s.top() << endl;

        //第一遍遍历
        //当前比前一个大，前一个暂时无法判断最大值，入栈
        //当前比前一个小，前一个可以判断最大值，出栈
        for (int i = 1; i < len; i++)
        {
            while (heights[i] < heights[s.top()])
            {
                cout << heights[i] << " " << heights[s.top()] << endl;
                //计算面积，弹栈
                int index = s.top();
                s.pop();
               
                    //弹出来的元素的len=前后俩元素的间隔，高度就是本下标的高度
                width = i - index;
                for (int j = index -1; j > 0 ; j--){
                    if(heights[j]>=heights[index]) width++;
                    else break;
                }
                
                area = max(area, heights[index] * width);
            }
            s.push(i);
        }
        //最后返回最大值
        return area;

        
    }
};
int main(int argc, char const *argv[])
{
    vector<int> heights{2, 1, 5, 6, 2, 3};
    // vector<int> heights{5,4,1,2};
    Solution s;
    int res = s.largestRectangleArea(heights);
    cout<<res;
    return 0;
}
