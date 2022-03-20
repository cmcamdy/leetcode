#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace ::std;

class Solution
{
public:
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen)
    {
        //表示连续白色的个数
        int len = 0, sum = 0;
        vector<vector<int>> dp(numCarpets, vector<int>(floor.size(), 0));
        vector<int> fsum(floor.size(), 0);
        // 计算一下前缀和
        for (int i = 0; i < floor.size(); i++)
        {
            if (floor[i] == '1')
            {
                sum++;
            }
            fsum[i] = sum;
        }
        
        dp[0][0] = fsum[carpetLen > floor.size() ? (floor.size() - 1) : (carpetLen - 1)];
        for (int i = 1; i < floor.size(); i++)
        {
            dp[0][i] = max(fsum[i + carpetLen > floor.size() ? (floor.size() - 1) : (i + carpetLen - 1)] - fsum[i - 1], dp[0][i-1]);
        }
        for (int i = 1; i < numCarpets; i++)
        {
            for (int j = 0; j < floor.size(); j++)
            {
                if (j < (i * carpetLen))
                    dp[i][j] = fsum[(j + carpetLen) > floor.size() ? (floor.size() - 1) : (j + carpetLen - 1)];
                else
                    dp[i][j] = max(fsum[(j + carpetLen) > floor.size() ? (floor.size() - 1) : (j + carpetLen - 1)] - fsum[j - 1] + dp[i - 1][j - carpetLen], dp[i][j - 1]);
            }
        }
        return sum - dp[numCarpets - 1][floor.size() - 1];
    }
};

int main()
{
    string text = "10110101";
    Solution s;
    cout << s.minimumWhiteTiles(text, 2, 2);
    string text2 = "111111111101001101111110001011111111111111111111011111111111111111111101101011111111111111101100010010111111100111110010110111110111111111100011111011111011111111111110100110101011111111110101001111101111110111111111111101";
    cout << s.minimumWhiteTiles(text2, 43, 5);

}
