#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <unordered_set>
#include <unordered_map>
using namespace ::std;

class Solution
{
public:
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {
        // 可以转换成邻接矩阵，然后查询就好了
        unordered_map<string, vector<pair<string, double>>> graph;
        for (int i = 0; i < equations.size(); i++)
        {
            graph[equations[i][0]].push_back({equations[i][1], values[i]});
            graph[equations[i][1]].push_back({equations[i][0], 1 / values[i]});
        }
        vector<double> res(queries.size(), -1.0);
        for (int i = 0; i < queries.size(); i++)
        {
            //保证二者存在
            if (graph.count(queries[i][0]) && graph.count(queries[i][1]))
            {
                unordered_set<string> visited;
                res[i] = dfs(graph, visited, queries[i][0], queries[i][1], 1);
            }
        }
        return res;
    }
    double dfs(unordered_map<string, vector<pair<string, double>>> &graph, unordered_set<string> &visited, string start, string end, double val)
    {
        if (start == end)
            return val;
        visited.insert(start);
        for (auto &node : graph[start])
        {
            if (!visited.count(node.first))
            {
                double ret = dfs(graph, visited, node.first, end, node.second * val);
                if (ret > 0)
                {
                    return ret;
                }
            }
        }
        return -1;
    }
};