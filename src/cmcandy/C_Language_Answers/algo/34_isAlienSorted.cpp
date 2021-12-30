

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <map>
#include <algorithm>
using namespace ::std;

class Solution
{
public:
    bool isAlienSorted(vector<string> &words, string order)
    {
        int letter[26];
        for (int i = 0; i < 26; i++)
        {
            letter[order[i] - 'a'] = i;
        }
        int len = words.size();
        int maxlen = 0;

        int len1 = words[0].size(), len2;
        for (int i = 1; i < len; i++)
        {
            len2 = words[i].size();
            bool jud = false;
            for (int j = 0; j < min(len1, len2); j++)
            {
                if (letter[words[i - 1][j] - 'a'] > letter[words[i][j] - 'a'])
                    return false;
                else if (letter[words[i - 1][j] - 'a'] < letter[words[i][j] - 'a'])
                {
                    jud = true;
                    break;
                }
            }

            if (jud == true || len1 <= len2)
            {
                len1 = len2;
                continue;
            }
            else
                return false;
        }
        return true;
    }
};

int main()
{
    Solution s;
    vector<string> words = {"word", "world", "row"};
    string letters = "worldabcefghijkmnpqstuvxyz";
    s.isAlienSorted(words, letters);
}