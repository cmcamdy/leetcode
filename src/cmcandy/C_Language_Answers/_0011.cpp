#include <iostream>
#include <vector>
#include <math.h>
using namespace ::std;
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int left = 0, right = height.size() - 1;
        int area = 0;

        while(left<right){
            // area = max(area,min(height[right],height[left])*(right-left));
            int s = height[right]<height[left]?height[right]:height[left];
            int newarea = s*(right-left);
            area = area>newarea?area:newarea;
            if (height[left]<height[right])
            {
                left++;
            }
            else{
                right--;
            }
        }
        return area;
    }
};
