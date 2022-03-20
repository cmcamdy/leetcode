#include <iostream>
#include <vector>
#include <string>
using namespace ::std;

class Solution
{
public:
    long long getDescentPeriods(vector<int> &prices)
    {
        long long nowlen = 1;
        long long res = 0;
        for(int i=1; i<prices.size(); i++){
            if(prices[i]==prices[i-1]-1) nowlen++;
            else{
                res += (1+nowlen)*nowlen/2;
                nowlen = 1;
            }
        }
        res += (1+nowlen)*nowlen/2;
        return res;
    }
    // long long getDescentPeriods(vector<int> &prices)
    // {
    //     vector<vector<long long>> dp(prices.size(), vector<long long>(prices.size(), 1));
    //     for (int j = 0; j < prices.size() - 1; j++)
    //     {
    //         dp[j][j + 1] = dp[j][j + 1 - 1] + (prices[j + 1 - 1] - prices[j + 1] == 1 ? 2 : 1);
    //     }
    //     for (int i = 2; i < prices.size(); i++)
    //     {
    //         for (int j = 0; j < prices.size() - i; j++)
    //         {
    //             dp[j][j + i] = dp[j][j + i - 1] + (prices[j + i - 1] - prices[j + i] == 1 ? dp[j + 1][j + i] : 1);
    //         }
    //     }
    //     return dp[0][prices.size() - 1];
    // }
};

int main()
{
    Solution s;
    // vector<int> prices = {3, 2, 1, 4};
    // vector<int> prices = {8,6,7,7};
    vector<int> prices = {12,11,10,9,8,7,6,5,4,3,4,3,10,9,8,7};
    cout << s.getDescentPeriods(prices);
}