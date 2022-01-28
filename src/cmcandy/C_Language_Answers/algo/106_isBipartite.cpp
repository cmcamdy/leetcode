#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace ::std;

class Solution
{
public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        // 着色问题
        int len = graph.size();
        //开始时无色
        vector<int> point(len, -1);
        queue<int> q;
        point[0] = 0;
        q.push(0);
        while (!q.empty())
        {
            int i = q.front();
            q.pop();
            for (auto &index : graph[i])
            {
                if (point[index] == -1)
                {
                    point[index] = (point[i] + 1) % 2;
                    q.push(index);
                }
                else
                {
                    if (point[index] == point[i])
                        return false;
                }
            }
            // 这里是防止有两个不相连的图出现
            if (q.empty())
            {
                for (int j = 0; j < len; j++)
                {
                    if (point[j] == -1)
                    {
                        point[j] = 0;
                        q.push(j);
                        break;
                    }
                }
            }
        }

        return true;
    }
};

int main()
{
}