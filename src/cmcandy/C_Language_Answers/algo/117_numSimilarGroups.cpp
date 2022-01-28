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
    int total;
    bool checkSimilar(string str1, string str2)
    {
        // 这里默认str是相同长度的且都是换位词
        int len = str1.size();
        int diff=0, index=0;
        while(index < len && diff<=2){
            if (str1[index] != str2[index])
                diff++;
            index++;
        }
        if(diff<=2) return true;
        return false;
    }
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
            total--;
            return true;
        }
    }
    int numSimilarGroups(vector<string> &strs)
    {
        int len = strs.size();
        total = len;
        vector<int> checkSet(len, -1);
        vector<int> rank(len, 1);
        for (int i = 0; i < len; i++)
        {
            for (int j = i + 1; j < len; j++)
            {
                if (checkSimilar(strs[i], strs[j]))
                {
                    unionVec(checkSet, rank, i, j);
                }
            }
        }
        return total;
    }
};

