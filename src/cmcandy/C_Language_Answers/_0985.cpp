#include <iostream>
#include <string>
#include <vector>
using namespace ::std;
class Solution
{
public:
    vector<int> sumEvenAfterQueries(vector<int> &A, vector<vector<int>> &queries)
    {

        //首先获得偶数值之和（sum），其次对于queries中的不同情况分奇偶讨论
        int sum = 0;
        int len = A.size();
        int lenQ = queries.size();
        vector<int> res;
        for (int i = 0; i < len; i++)
        {
            if (A[i] % 2 == 0)
                sum += A[i];
        }
        for (int i = 0; i < lenQ; i++)
        {
            A[queries[i][1]] += queries[i][0];
            if (queries[i][0] % 2 != 0)
            {
                //奇数+偶==》sum-=
                //奇数+奇==》sum+=
                sum += A[queries[i][1]] % 2 == 0 ? A[queries[i][1]] : -A[queries[i][1]] + queries[i][0];
            }
            else if (A[queries[i][1]] % 2 == 0)
                sum += queries[i][0];
            res.push_back(sum);
        }
        return res;
    }
};