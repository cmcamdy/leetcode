#include <iostream>
#include <vector>
using namespace ::std;
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        // dp 二维数组，表示以这个点为右下角的正方形的边长
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        int maxNum = 0;
        //初始化第一行/列
        for( int i = 0; i<m; i++){
            dp[i][0] = matrix[i][0] == '1'? 1:0;
            maxNum = max(dp[i][0],maxNum);
        }
        for( int j = 0; j<n; j++){
            dp[0][j] = matrix[0][j] == '1'? 1:0;
            maxNum = max(dp[0][j],maxNum);
        }
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if(matrix[i][j]=='1')
                    dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1])) + 1;
                else   
                    dp[i][j] = 0;
                maxNum = max(dp[i][j],maxNum);
            }
        }
        return maxNum*maxNum;
    }
};
int main(){

    // vector<vector<int>> nums = {{1,0,1,0,0},{1,0,1,1,1},{1,1,1,1,1},{1,0,0,1,0}};
    vector<vector<char>> nums = {{'1','0','1','1','0','1'},{'1','1','1','1','1','1'},{'0','1','1','0','1','1'},{'1','1','1','0','1','0'},{'0','1','1','1','1','1'},{'1','1','0','1','1','1'}};
    Solution s;
    cout<<s.maximalSquare(nums);
}