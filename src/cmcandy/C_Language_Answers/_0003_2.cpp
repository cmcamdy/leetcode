#include <iostream>
#include <map>
#include <math.h>
#include <unordered_set>
using namespace ::std;
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        //初始化
        map<char,int> letter;
        int len = s.size();
        // int tmp;
        int left = 0, res = 0;
        if (len == 0)
            return 0;
        for (int i = 0; i < len; i++)
        {
            
            //这个字母没用过，记上
            if (  letter.find(s[i])==letter.end())
                letter[s[i]] = i;
            //用过，更新，并更新left
            else if (letter[s[i]] >= left)
            {
                res = max(res, i - left);
                left = letter[s[i]]+1;
                letter[s[i]] = i;
            }
        }
        return res > len - left ? res : len - left;
    }
};
int main(int argc, char const *argv[])
{
    Solution s;
    // s.lengthOfLongestSubstring("   ");
    s.lengthOfLongestSubstring("aabaab!bb");
    
    return 0;
}
