#include <iostream>
#include <vector>

using namespace ::std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
    
        int len = nums.size();
        int sum = len;
        for(int i =0;i<len;i++){
            sum+=i-nums[i];
        }
        return sum;
    }
};