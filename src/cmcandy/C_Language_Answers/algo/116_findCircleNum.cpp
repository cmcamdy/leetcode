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
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        vector<int> checkSet(isConnected.size(), -1);
        vector<int> rank(isConnected.size(), 1);
        for (int i = 0; i < isConnected.size(); i++)
        {
            for (int j = i + 1; j < isConnected[0].size(); j++)
            {
                if (isConnected[i][j] == 1)
                {
                    unionVec(checkSet, rank, i, j);
                }
            }
        }
        int num = 0;
        for (int i = 0; i < checkSet.size(); i++)
        {
            if (checkSet[i] == -1)
                num++;
        }
        return num;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> isConnected = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
    cout<<s.findCircleNum(isConnected);
}