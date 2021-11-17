#include <iostream>
#include <string>
#include <vector>
using namespace ::std;
class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        int letter[26];
        int len = s.size();
        vector<int> res;
        for (int i = 0; i < len; i++)
        {
            letter[s[i] - 'a'] = i;
        }
        int start = 0, end = letter[s[0] - 'a'];
        for (int i = 0; i < len; i++)
        {
            end = max(letter[s[i] - 'a'], end);
            if (i == end)
            {
                res.push_back(end - start + 1);
                start = i + 1;
            }
        }
        return res;
    }
};