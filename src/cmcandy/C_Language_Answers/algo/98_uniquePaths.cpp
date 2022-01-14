#include <iostream>
#include <vector>
#include <string>
using namespace ::std;
class Solution {
public:
    int uniquePaths(int m, int n) {
        if( m==1 || n==1) return 1;
        // 可以直接用排列组合公式写，此处用DPDP
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i=1; i<m; i++){
            dp[i][0] = 1;
        }
        for(int j=1; j<n; j++){
            dp[0][j] = 1;
        }
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};