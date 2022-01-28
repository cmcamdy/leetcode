#include <iostream>
#include <vector>
#include <string>
using namespace ::std;
class Solution
{
public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int row = grid.size(), col = grid[0].size();
        int maxArea = 0;
        vector<vector<int>> matrix(row, vector<int>(col, 0));

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][j] = 1;
                    if (grid[i][j] == 1)
                        maxArea = max(findIsland(i, j, grid, matrix, row, col), maxArea);
                }
            }
        }
        return maxArea;
    }
    int findIsland(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &matrix, int row, int col)
    {
        int now = 1;
        // 上侧
        if (i > 0 && matrix[i - 1][j] == 0 && grid[i - 1][j] == 1)
        {
            matrix[i - 1][j] = 1;
            now += findIsland(i - 1, j, grid, matrix, row, col);
        }
        //左侧
        if (j > 0 && matrix[i][j - 1] == 0 && grid[i][j - 1] == 1)
        {
            matrix[i][j - 1] = 1;
            now += findIsland(i, j - 1, grid, matrix, row, col);
        }
        //下侧
        if (i < row - 1 && matrix[i + 1][j] == 0 && grid[i + 1][j] == 1)
        {
            matrix[i + 1][j] = 1;
            now += findIsland(i + 1, j, grid, matrix, row, col);
        }
        //右侧
        if (j < col - 1 && matrix[i][j + 1] == 0 && grid[i][j + 1] == 1)
        {
            matrix[i][j + 1] = 1;
            now += findIsland(i, j + 1, grid, matrix, row, col);
        }
        return now;
    }
};

int main()
{

    vector<vector<int>> grid = {{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0}, {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0}, {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};
    Solution s;
    cout << s.maxAreaOfIsland(grid);
}