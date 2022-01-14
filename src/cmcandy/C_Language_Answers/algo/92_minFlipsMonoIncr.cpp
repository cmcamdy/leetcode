#include <iostream>
#include <vector>
#include <string>
using namespace ::std;
class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int len = s.size();
        // f 表示 最后一个为0的最小反转次数
        // g 表示 最后一个为1的最小反转次数
        // if 1 f[i] = f[i-1]+1,g[i] = min(g[i-1],f[i-1])
        // if 0 f[i] = f[i-1],g[i] = min(g[i-1],f[i-1])+1
        vector<int> f(len,0);
        vector<int> g(len,0);
        f[0] = s[0] == '1'?1:0;
        g[0] = s[0] == '1'?0:1;
        for(int i=1; i<len; i++){
            if(s[i] == '1'){
                f[i] = f[i-1] + 1;
                g[i] = min(f[i-1],g[i-1]);
            }else if(s[i] == '0'){
                f[i] = f[i-1];
                g[i] = min(f[i-1],g[i-1]) + 1;
            }
        }
        return min(f[len-1],g[len-1]);
    }
};