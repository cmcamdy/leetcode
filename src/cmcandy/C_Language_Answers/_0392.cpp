#include <iostream>
#include <vector>
using namespace ::std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int indexs = 0;
        int lent = t.size();
        int lens = s.size();
        for(int i =0; i<lent; i++){
            if(indexs==lens) return true;
            if(t[i]==s[indexs]) indexs++;
        }
        return indexs==lens?true:false;
    }
};