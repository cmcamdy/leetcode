#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace ::std;
class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        //拓扑算法
        //构造一个图，用邻接矩阵
        vector<int> tmp(numCourses, 0);
        int len = prerequisites.size();
        if (len == 0)
            return true;
        vector<vector<int>> dp(numCourses, vector<int>(1, -1));

        //构造邻接表
        for (int i = 0; i < len; i++)
        {
            tmp[prerequisites[i][0]]++;
            dp[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        //执行拓扑算法
        int count = numCourses;
        int jud = 0;
        while (count > 1)
        {
            jud = 0;
            for (int i = 0; i < numCourses; i++)
            {
                if (tmp[i] == 0)
                {
                    //入度位0的点，移除
                    jud = 1;
                    for (int j = 1; j < dp[i].size(); j++)
                    {
                        tmp[dp[i][j]]--;
                    }
                    tmp[i]--;
                    count--;
                    break;
                }
            }
            if (jud == 0)
                return false;
        }
        return true;
    }
};