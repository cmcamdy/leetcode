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
    int findRoot(vector<int> checkSet, int index)
    {
        int root_index = index;
        while (checkSet[root_index] != -1)
        {
            root_index = checkSet[root_index];
        }
        return root_index;
    }
    bool unionVec(vector<int> &checkSet, vector<int> &rank, int x, int y)
    {
        int x_root = findRoot(checkSet, x);
        int y_root = findRoot(checkSet, y);

        if (x_root == y_root)
        {
            return false;
        }
        else
        {
            if (rank[x_root] > rank[y_root])
            {
                swap(x_root, y_root);
            }
            else if (rank[x_root] == rank[y_root])
            {
                rank[y_root]++;
            }
            checkSet[x_root] = y_root;
            return true;
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        int len = edges.size();
        // 这里题目说了 n == edges.size()，所以才能这么写，不然还得遍历一遍得到所有节点的id
        vector<int> checkSet(len + 1, -1);
        vector<int> rank(len + 1, 1);
        for (int i = 0; i < len; i++)
        {
            if (!unionVec(checkSet, rank, edges[i][0], edges[i][1]))
                return edges[i];
        }
        return rank;
    }
};