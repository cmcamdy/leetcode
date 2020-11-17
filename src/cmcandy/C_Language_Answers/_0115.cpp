#include <iostream>
#include <math.h>
#include <vector>
using namespace ::std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int slen=s.size();
        int tlen=t.size();
        vector<vector<long>> dp(tlen+1,vector<long>(slen+1,0));

        
        for(int i =0;i<slen;i++){
            dp[0][i]=1;
        }
        for(int i=0;i<slen;i++){
            for(int j =0;j<tlen;j++){
                if(s[i]==t[j]) dp[j+1][i+1]=dp[j][i]+dp[j+1][i];
                else dp[j+1][i+1]=dp[j+1][i];
            }
        }
        return dp[tlen][slen];

    }
};