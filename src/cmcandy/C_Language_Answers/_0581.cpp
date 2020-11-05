#include <iostream>
#include <string>
#include <vector>
using namespace ::std;
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        //初始化
        int len = nums.size();
        int min = nums[len-1];
        int max = nums[0];//无序区间的最大数
        int begin=0,end=-1;
        //遍历
        for(int i =0;i<len;i++){
            //若当前遍历数比max小，说明end边界需要后移（即这个数在无区间）
            if(nums[i]<max){
                end = i;
            }else{
                //找到更大的无序区间的数
                max = nums[i];
            }
            //如果当前值比最小值要大，则说明区间有序，则可以将begin边界往后移，
            if(nums[len-i-1]>min){
                begin = len-i-1;
            }else{
                min = nums[len-i-1];
            }
        }
        return end-begin+1;
    }
};