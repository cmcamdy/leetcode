#include <iostream>
#include <vector>
#include <algorithm>
using namespace ::std;
class Solution
{
public:
    string removeDuplicateLetters(string s)
    {
        int len = s.size();
        vector<int> hash(26, 0);
        vector<int> used(26, 0);
        //数组栈，index为指针
        vector<char> sta(26, 96);
        int index = 0;
        //记录出现次数
        for (int i = 0; i < len; i++)
        {
            hash[s[i] - 'a']++;
        }
        sta[0] = s[0];
        hash[s[0] - 'a']--;
        used[s[0] - 'a']++;
        for (int i = 1; i < len; i++)
        {
            //当前值没用过+当前值比栈顶小+栈顶的值后面还有一个
            while (index >= 0 && sta[index] > s[i] && hash[sta[index] - 'a'] > 0 && used[s[i] - 'a'] == 0)
            {
                used[sta[index] - 'a'] = 0;
                index--;
            }
            if (used[s[i] - 'a'] == 0)
            {
                //入场
                sta[++index] = s[i];
                used[s[i] - 'a'] = 1;
            }
            hash[s[i] - 'a']--;
        }
        string res;
        res.assign(sta.begin(), sta.begin() + index + 1);
        return res;
    }
};
int main(int argc, char const *argv[])
{
    Solution s;
    string res = s.removeDuplicateLetters("abacb");
    cout << res;
    return 0;
}
