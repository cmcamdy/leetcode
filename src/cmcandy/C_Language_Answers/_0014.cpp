#include <iostream>
#include <vector>
#include <string>

using namespace::std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(!strs.size()) return "";

        int length = strs[0].size();
        int count  = strs.size();

        for (int i = 0; i < length; i++)
        {
            char tmp = strs[0][i];
            for (int j = 1; j < count; j++)
            {
                //如果不相等
                if (i==strs[j].size()||strs[j][i]!=tmp)
                {
                    return strs[0].substr(0,i);
                }
            }
        }
        return strs[0];         
    }
};
int main(){

    Solution s;
    vector<string> str({"c","c"});
    cout<<s.longestCommonPrefix(str);
}