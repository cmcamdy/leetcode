#include <iostream>
#include <vector>

using namespace ::std;

//KMP 算法
class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        if (needle.empty())
            return 0;
        int i = 0, m = haystack.size();
        int j = 0, n = needle.size();
        vector<int> nextVal = get_nextVal(needle);
        while (i<m&&j<n)
        {
            if(j==-1||needle[j]==haystack[i])i++,j++;
            else j = nextVal[j];
        }
        return j==n?i-j:-1;
    }

    vector<int> get_next(const string &pat)
    {
        int n=pat.size();
        vector<int> next(n+1,-1);
        int k=-1,j=0;
        while(j<n){
            if(k==-1||pat[k]==pat[j]) next[++j]==++k;
            else k = next[k];
        }
        return next;
    }

    vector<int> get_nextVal(const string &pat)
    {
        int n = pat.size();
        vector<int> nextVal(n, -1);
        int k = -1, j = 0;
        while (j < n - 1)
        {
            if (k == -1 || pat[k] == pat[j])
            {
                k++, j++;
                if (pat[j] != pat[k])
                    nextVal[j] = k;
                else
                    nextVal[j] = nextVal[k];
            }
            else
            {
                k = nextVal[k];
            }
        }
        return nextVal;
    }
};