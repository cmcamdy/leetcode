#include <iostream>
#include <vector>
#include <algorithm>
using namespace ::std;
class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        //有个矩阵和
        int sum = 0;
        int m = mat.size();
        int n = mat[0].size();
        int km = min(K+1,m),kn = min(K+1,n);
        vector<vector<int>> res(m,vector<int>(n,0));
        //初始化sums[0]
        for(int i = 0;i<km; i++){
            for(int j = 0;j<kn;j++){
                sum+=mat[i][j];
            }
        }
        res[0][0] = sum;
        //填充第一列
        for(int i = 1;i<m; i++){
            res[i][0] = res[i-1][0];
            if(i-K>0){
               for(int j = 0;j<kn;j++){
                res[i][0] -= mat[i-K-1][j];
                } 
            }
            if(i+K<m){
                for(int j = 0;j<kn;j++){
                    res[i][0] += mat[i+K][j];
                }   
            }
        }
        //填充每一行
        for(int i = 0; i<m; i++){
            for(int j = 1; j<n; j++){
                res[i][j] = res[i][j-1];
                if(j-K>0){
                    for(int x = max(0,i-K);x<min(m,i+K+1);x++){
                        res[i][j] -= mat[x][j-K-1];
                    } 
                }
                if(j+K<n){
                    for(int x = max(0,i-K);x<min(m,i+K+1);x++){
                        res[i][j] += mat[x][j+K];
                    } 
                }
                
            }
        }

        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    // vector<vector<int>> mat{{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>> mat{{76,4,73},{21,8,56},{4,56,61},{70,32,38},{31,94,67}};
    s.matrixBlockSum(mat,1);
    return 0;
}

