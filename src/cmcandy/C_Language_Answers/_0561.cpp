#include <iostream>
#include <string>
#include <vector>
using namespace ::std;

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int len = nums.size();
        sort(nums,0,len-1);
        int res = 0;
        // ::sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size();i+=2){
            res += nums[i];
        }
        return res;
    }
    void sort(vector<int>& nums,int first,int last){
        if(first>=last) return;
        int jud = 0;
        int left=first,right=last;
        while(left<right){
            if(nums[left]>nums[right]){
                swap(nums[left],nums[right]);
                jud=(jud+1)%2;
            }
            if(jud==1) left++;
            else if(jud==0) right--;
        }
        sort(nums,0,left-1);
        sort(nums,left+1,last);
    }
};
int main(){
    vector<int> nums({1,4,3,2});
    Solution s;
    s.arrayPairSum(nums);
}