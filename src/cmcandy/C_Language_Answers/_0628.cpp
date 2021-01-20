#include <iostream>
#include <string>
#include <vector>
using namespace ::std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int len = nums.size();

        if(len == 3) return nums[0]*nums[1]*nums[2];
        
        //三个数最大（正）有以下几种可能
            //1、三正
            //2、一正二负
            //3、三负
        //因此需要取三个最大值，以及两个最小值
        //其中1、3表示在max1，2、3中取，2可能取到两个负的min
        int max1=-1000,max2=-1000,max3=-1000,min1=1000,min2=1000;
        for(int i = 0; i< len; i++){
            //维护两个最小值
            if(nums[i]<min1){
                min2=min1;
                min1=nums[i];
            }
            else if(nums[i]<min2){
                min2=nums[i];
            }
            //维护三个最大值
            if(nums[i]>max1){
                max3 = max2;
                max2 = max1;
                max1 = nums[i];
            }
            else if(nums[i]>max2){
                max3 = max2;
                max2 = nums[i];
            }
            else if(nums[i]>max3){
                max3 = nums[i];
            }
        }
    return max(max1*max2*max3,max1*min1*min2);
    }
};