#include <iostream>
#include <string>
#include <vector>
using namespace ::std;
class Solution
{
public:
    int len1, len2, len3;
    string st1, st2, st3;
    bool isInterleave(string s1, string s2, string s3)
    {
        if (s1 == "" && s2 == "" && s3 == "")
            return true;
        len1 = s1.size();
        len2 = s2.size();
        len3 = s3.size();
        st1 = s1;
        st2 = s2;
        st3 = s3;
        if (len1 + len2 != len3)
            return false;
        else if (len1 == 0) 
     0-       return st2.compare(st3) == 0;
        else if (len2 == 0)
            return st1.compare(st3) == 0;
        // return judge(0, 0, 0);
        return judge_v2();
    }

    bool judge_v2()
    {

        // bool dp[len1][len2];
        vector<vector<bool>> dp(len1 + 1, vector<bool>(len2 + 1, false));
        //dp初始化
        dp[0][0] = true;
        int jud = true;
        for (int i = 1; i <= len1; i++)
        {
            if (st1[i - 1] != st3[i - 1])
                jud = false;
            dp[i][0] = jud;
        }
        jud = true;
        for (int i = 1; i <= len2; i++)
        {
            if (st2[i - 1] != st3[i - 1])
                jud = false;
            dp[0][i] = jud;
        }
        for (int i = 1; i < len1 + 1; i++)
        {
            for (int j = 1; j < len2 + 1; j++)
            {
                dp[i][j] = (dp[i][j - 1] && st3[i + j - 1] == st2[j - 1]) || (dp[i - 1][j] && st3[i + j - 1] == st1[i - 1]);
            }
        }
        return dp[len1][len2];
    }

    bool judge(int index1, int index2, int index3)
    {
        //何时返回true?

        //有一边比较完毕了
        if (index1 == len1)
            return st2.compare(index2, len2 - index2, st3, index3, len3 - index3) == 0;
        else if (index2 == len2)
            return st1.compare(index1, len1 - index1, st3, index3, len3 - index3) == 0;

        //何时直接返回false? st1[index1]!=st3[index3] && st2[index2]!=st3[index3]
        if (st1[index1] != st3[index3] && st2[index2] != st3[index3])
            return false;
        //单边相等
        else if (st1[index1] == st3[index3] && st2[index2] != st3[index3])
        {
            return judge(index1 + 1, index2, index3 + 1);
        }
        else if (st1[index1] != st3[index3] && st2[index2] == st3[index3])
        {
            return judge(index1, index2 + 1, index3 + 1);
        }
        //何时分支？s1[index1]==s2[index2] && s1[index1]==s3[index3]
        else if (st1[index1] == st2[index2] && st1[index1] == st3[index3])
        {
            return judge(index1 + 1, index2, index3 + 1) || judge(index1, index2 + 1, index3 + 1);
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    string a = "a";
    string c = "a";
    cout << s.isInterleave("aabcc", "dbbca", "aadbbcbcac");
    // cout << s.isInterleave("c", "ca", "cac");
    // cout << s.isInterleave("c", "ca", "cac");
    return 0;
}
