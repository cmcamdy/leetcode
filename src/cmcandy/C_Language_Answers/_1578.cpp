#include <iostream>
#include <vector>
#include <algorithm>
using namespace ::std;

class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        int len = cost.size();
        int sum = 0;
        for(int i = 1; i<len; i++){
            if(s[i]==s[i-1]){
                if(cost[i]<cost[i-1]){
                    sum += cost[i];
                    cost[i] = cost[i-1];
                }else{
                    sum += cost[i-1];
                }
            }
        }
        return sum;
    }
};