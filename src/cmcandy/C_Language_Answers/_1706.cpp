#include <iostream>
#include <vector>
using namespace ::std;
class Solution
{
public:
    vector<int> findBall(vector<vector<int>> &grid)
    {
        int col = grid[0].size();
        int row = grid.size();
        vector<int> ball(col, -1);
        //球坐标
        int x = 0, y = 0;
        //每个球开始一个一个走
        for (int i = 0; i < col; i++)
        {
            x = 0;
            y = i;
            while (true)
            {
                //到达底部
                if (x == row)
                {
                    ball[i] = y;
                    break;
                }
                //左侧墙壁
                else if (y == 0 && grid[x][y] == -1)
                    break;
                //右侧墙壁
                else if (y == (col - 1) && grid[x][y] == 1)
                    break;
                //右走v字
                else if (grid[x][y] == 1 && grid[x][y + 1] == -1)
                    break;
                //向右下方走
                else if (grid[x][y] == 1 && grid[x][y + 1] == 1)
                {
                    x++;
                    y++;
                }
                //左走v字
                else if (y > 0 && grid[x][y] == -1 && grid[x][y - 1] == 1)
                    break;
                //向左下方走
                else if (y > 0 && grid[x][y] == -1 && grid[x][y - 1] == -1)
                {
                    x++;
                    y--;
                }
                cout << i << ". " << x << ". " << y << endl;
            }
            // cout<<i<<". "<<ball[i]<<endl;
        }
        return ball;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<vector<int>> grid{{1, 1, 1, -1, -1}, {1, 1, 1, -1, -1}, {-1, -1, -1, 1, 1}, {1, 1, 1, 1, -1}, {-1, -1, -1, -1, -1}};
    s.findBall(grid);
    return 0;
}
