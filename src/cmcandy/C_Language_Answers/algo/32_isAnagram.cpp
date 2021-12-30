
#include <iostream>
#include <vector>
#include <string>
using namespace ::std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s == t)
            return false;
        int lens = s.size(), lent = t.size();
        if (lens != lent)
            return false;
        vector<int> letter(26, 0);
        for (int i = 0; i < lens; i++)
        {
            letter[s[i] - 'a']++;
        }
        for (int i = 0; i < lens; i++)
        {
            letter[t[i] - 'a']--;
            if (letter[t[i] - 'a'] < 0)
                return false;
        }
        return true;
    }
};