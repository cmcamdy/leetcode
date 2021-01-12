#include <iostream>
#include <string>
#include <vector>
using namespace ::std;
class Solution
{
public:
    vector<vector<int>> transpose(vector<vector<int>> &A)
    {
        int wid = A.size();
        int len = A[0].size();
        vector<vector<int>> res(len, vector<int>(wid, 0));

        for (int i = 0; i < len; i++)
        {
            for (int j = 0; j < wid; j++)
            {
                res[i][j] = A[j][i];
            }
        }
        return res;
    }
};