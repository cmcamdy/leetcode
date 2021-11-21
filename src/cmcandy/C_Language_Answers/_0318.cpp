#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace ::std;

class Solution
{
public:
    int maxProduct(vector<string> &words)
    {
        int len = words.size();
        int mask[len];
        map<int, int> m;
        for (int i = 0; i < len; i++)
        {
            mask[i] = 0;
            for (int j = 0; j < words[i].size(); j++)
            {
                mask[i] |= 1 << (words[i][j] - 'a');
            }
            if (m.find(mask[i]) != m.end())
            {
                m[mask[i]] = words[i].size() > m[mask[i]] ? words[i].size() : m[mask[i]];
            }
            else
            {
                m[mask[i]] = words[i].size();
            }
        }
        map<int, int>::iterator iti, itj;
        int res = 0;
        for (iti = m.begin(); iti != m.end(); ++iti)
        {
            for (itj = m.find(iti->first) ; itj != m.end(); ++itj)
            {
                if ((iti->first & itj->first) == 0)
                {
                    res = max(res, iti->second * itj->second);
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<string> words = {"abcw", "baz", "foo", "bar", "xtfn", "abcdef"};
    s.maxProduct(words);
}