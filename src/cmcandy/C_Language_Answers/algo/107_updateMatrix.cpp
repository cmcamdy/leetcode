#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace ::std;

class Solution
{
public:
    queue<vector<int>> que;

    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int row = mat.size(), col = mat[0].size();
        int maxlen = max(row, col);
        vector<vector<int>> resMat(row, vector<int>(col, maxlen));
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (mat[i][j] == 0)
                {
                    resMat[i][j] = 0;
                    que.push({i, j});
                }
            }
        }

        while (!que.empty())
        {
            auto pos = que.front();
            que.pop();
            if (pos[0] > 0)
            {
                if (mat[pos[0] - 1][pos[1]] == 1 && resMat[pos[0] - 1][pos[1]] > resMat[pos[0]][pos[1]] + 1)
                {
                    resMat[pos[0] - 1][pos[1]] = resMat[pos[0]][pos[1]] + 1;
                    que.push({pos[0] - 1, pos[1]});
                }
            }
            if (pos[0] < row - 1)
            {
                if (mat[pos[0] + 1][pos[1]] == 1 && resMat[pos[0] + 1][pos[1]] > resMat[pos[0]][pos[1]] + 1)
                {
                    resMat[pos[0] + 1][pos[1]] = resMat[pos[0]][pos[1]] + 1;
                    que.push({pos[0] + 1, pos[1]});
                }
            }
            if (pos[1] > 0)
            {
                if (mat[pos[0]][pos[1] - 1] == 1 && resMat[pos[0]][pos[1] - 1] > resMat[pos[0]][pos[1]] + 1)
                {
                    resMat[pos[0]][pos[1] - 1] = resMat[pos[0]][pos[1]] + 1;
                    que.push({pos[0], pos[1] - 1});
                }
            }
            if (pos[1] < col - 1)
            {
                if (mat[pos[0]][pos[1] + 1] == 1 && resMat[pos[0]][pos[1] + 1] > resMat[pos[0]][pos[1]] + 1)
                {
                    resMat[pos[0]][pos[1] + 1] = resMat[pos[0]][pos[1]] + 1;
                    que.push({pos[0], pos[1] + 1});
                }
            }
        }
        return resMat;
    }
};

int main()
{
    Solution s;
    // vector<vector<int>> mat = {{0, 0, 0}, {0, 1, 0}, {1, 1, 1}};
    vector<vector<int>> mat = {{0, 0, 1, 0, 1, 1, 1, 0, 1, 1},
                               {1, 1, 1, 1, 0, 1, 1, 1, 1, 1},
                               {1, 1, 1, 1, 1, 0, 0, 0, 1, 1},
                               {1, 0, 1, 0, 1, 1, 1, 0, 1, 1},
                               {0, 0, 1, 1, 1, 0, 1, 1, 1, 1},
                               {1, 0, 1, 1, 1, 1, 1, 1, 1, 1},
                               {1, 1, 1, 1, 0, 1, 0, 1, 0, 1},
                               {0, 1, 0, 0, 0, 1, 0, 0, 1, 1},
                               {1, 1, 1, 0, 1, 1, 0, 1, 0, 1},
                               {1, 0, 1, 1, 1, 0, 1, 1, 1, 0}};

    s.updateMatrix(mat);
}