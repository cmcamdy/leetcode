#include <iostream>
#include <vector>

using namespace ::std;

class NumMatrix
{
public:
    vector<vector<int>> mymatrix;
    NumMatrix(vector<vector<int>> &matrix)
    {
        //意思是计算出某一点到（0,0）的和然后-上-左+左上
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>> tmp(row, vector<int>(col, 0));
        mymatrix = tmp;
        mymatrix[0][0] = matrix[0][0];
        for (int i = 1; i < row; i++)
        {
            //init 第0列
            mymatrix[i][0] = mymatrix[i - 1][0] + matrix[i][0];
            // cout<<mymatrix[i][0]<<endl;
        }
        for (int i = 1; i < col; i++)
        {
            //init 第0行
            mymatrix[0][i] = mymatrix[0][i - 1] + matrix[0][i];
            // cout<<mymatrix[0][i]<<endl;
        }
        for (int i = 1; i < row; i++)
        {
            for (int j = 1; j < col; j++)
            {
                mymatrix[i][j] = mymatrix[i - 1][j] + mymatrix[i][j - 1] - mymatrix[i - 1][j - 1] + matrix[i][j];
                // cout<<mymatrix[i][j]<<endl;
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        //=(r2,c2)-(r1-1,c2)-(r2,c1-1)+(r1-1,c1-1)
        int res = mymatrix[row2][col2];
        if (row1 > 0)
            res -= mymatrix[row1 - 1][col2];
        if (col1 > 0)
            res -= mymatrix[row2][col1 - 1];
        if (row1 > 0 && col1 > 0)
            res += mymatrix[row1 - 1][col1 - 1];
        return res;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

int main(int argc, char const *argv[])
{
    vector<vector<int>> nums{{-4, -5}};
    NumMatrix n(nums);
    n.sumRegion(0, 0, 0, 0);
    return 0;
}
