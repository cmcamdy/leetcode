#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <unordered_set>
using namespace ::std;

class Solution
{
public:
    vector<int> path;
    vector<vector<int>> res;
    int target;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        target = graph.size() - 1;
        path.push_back(0);
        backtrace(graph,0);
        return res;
    }

    void backtrace(vector<vector<int>> &graph, int index)
    {
        if (index == target)
        {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < graph[index].size(); i++)
        {
            path.push_back(graph[index][i]);
            backtrace(graph, graph[index][i]);
            path.pop_back();
        }
    }
};

int main()
{
    Solution s;
    vector<vector<int>> graph = {{1, 2}, {3}, {3}, {}};
    s.allPathsSourceTarget(graph);
}