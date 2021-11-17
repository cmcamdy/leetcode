#include <iostream>
#include <vector>
using namespace ::std;

int main()
{

    int len;
    cin >> len;
    int dp[len][len];
    cin >> dp[0][0];
    int tmp;
    for (int i = 1; i < len; i++)
    {
        cin >> dp[i][0];
        for (int j = 1; j < i; j++)
        {
            cin >> dp[i][j];
            dp[i][j] += min(dp[i - 1][j - 1], dp[i - 1][j]);
        }
        cin >> dp[i][i];
        dp[i][0] += dp[i - 1][0];
        dp[i][i] += dp[i - 1][i - 1];
    }
    int res = 10000;
    for (int j = 0; j < len; j++)
    {
        res = min(dp[len - 1][j], res);
    }
    cout << res;
}
