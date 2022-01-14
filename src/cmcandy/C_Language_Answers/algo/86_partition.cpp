#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace ::std;


class Solution {
public:
    string s;
    int len;
    vector<vector<int>> isPalindrome;
    vector<string> path;
    vector<vector<string>> res;
    vector<vector<string>> partition(string s) {
        this->s = s;
        this->len = s.size();
        vector<vector<int>> tmp(len,vector<int>(len,0));
        isPalindrome = tmp;
        for(int i=0; i<len; i++){
            isPalindrome[i][i] = 1;
        }
        for(int i=0; i<len-1; i++){
            isPalindrome[i][i+1] = (s[i]==s[i+1])?1:0;
        }
        for(int i=2; i<len; i++){
            for(int j=0; j+i<len; j++){
                isPalindrome[j][j+i] = (s[j]==s[j+i] && isPalindrome[j+1][j+i-1])?1:0;
            }
        }
        backtrace(0);
        return res;
    }
    void backtrace(int idx){
        if(idx == len){
            res.push_back(path);
        }

        for(int i=idx; i<len; i++){
            if(isPalindrome[idx][i]){
                path.push_back(s.substr(idx,i-idx+1));
                backtrace(i+1);
                path.pop_back();
            }
        }
    }
};


int main()
{
    Solution s;
    s.partition("google");
}



