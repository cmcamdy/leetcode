#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace ::std;


class Solution {
public:
    int len;
    string s;
    vector<string> path;
    vector<string> res;
    vector<string> restoreIpAddresses(string s) {
        this->s = s;
        this->len = s.size();
        backtrace(0);
        return res;
    }
    void backtrace(int idx){
        if(idx==len||path.size()>4){
            if(path.size()==4){
                // 这里res.push_back
                res.push_back(path[0]+'.'+path[1]+'.'+path[2]+'.'+path[3]);
            }
            return;
        }

        if(s[idx]=='0'){
            path.push_back("0");
            backtrace(idx+1);
            path.pop_back();
        }else{
            int tmp = s[idx]-'0';
            while(tmp<=255 && idx<len){
                path.push_back(to_string(tmp));
                backtrace(idx+1);
                path.pop_back();
                idx++;
                tmp = tmp*10 + s[idx]-'0';

            }
        }
    }
};


int main()
{
    Solution s;
    // s.restoreIpAddresses("0000");
    s.restoreIpAddresses("25525511135");
    
}



