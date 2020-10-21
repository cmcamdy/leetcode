#include <iostream>
#include <string>
#include <vector>

using namespace ::std;


class Solution {
public:
    bool isAnagram(string s, string t) {
            int len = s.length();
            if (t.length()!=len)
            {
                return false;
            }
            vector<int> v(26,0);

            for (int i = 0; i < len; i++)
            {
               v[s[i]-'a']++;
               v[t[i]-'a']--;
            }
            for (int i = 0; i < 26; i++)
            {
                if(v[i]!=0) return false;
            }
            
            return true;
    }
};