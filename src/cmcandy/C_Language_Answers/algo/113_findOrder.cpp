#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <unordered_set>
#include <unordered_map>
using namespace ::std;

class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        // 拓扑排序的题
        //表示课程的入度，即先导课程的数目
        vector<int> vecIns(numCourses, 0);
        map<int, vector<int>> m;
        // 保存入度为0的点
        queue<int> que;
        // res
        vector<int> res;
        for (int i = 0; i < prerequisites.size(); i++)
        {
            if (m.count(prerequisites[i][1]))
            {
                m[prerequisites[i][1]].push_back(prerequisites[i][0]);
            }
            else
            {
                vector<int> tmp = {prerequisites[i][0]};
                m[prerequisites[i][1]] = tmp;
            }
            vecIns[prerequisites[i][0]]++;
        }

        for (int i = 0; i < vecIns.size(); i++)
        {
            if (vecIns[i] == 0)
                que.push(i);
        }
        while (!que.empty())
        {
            int front = que.front();
            que.pop();
            if (m.count(front))
            {
                // 减去这些点的入度
                for (int i = 0; i < m[front].size(); i++)
                {
                    vecIns[m[front][i]]--;
                    if (vecIns[m[front][i]] == 0)
                        que.push(m[front][i]);
                }
            }
            res.push_back(front);
        }
        if(res.size()<numCourses){
            vector<int> tmp;
            res.clear();
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> prerequisites = {{1, 0}, {1, 2}, {0, 1}};
    s.findOrder(3, prerequisites);
}