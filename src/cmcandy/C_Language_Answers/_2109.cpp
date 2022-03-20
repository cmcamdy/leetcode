#include <iostream>
#include <vector>
#include <string>
using namespace ::std;

class Solution
{
public:
    string addSpaces(string s, vector<int> &spaces)
    {
        string res;
        int index = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (index<spaces.size() && spaces[index] == i)
            {
                res.push_back(' ');
                index++;
            }
            res.push_back(s[i]);
        }
        return res;
    }

    // string addSpaces(string s, vector<int> &spaces)
    // {
    //     string res = "";
    //     int start = 0,index=0;
    //     if(spaces[start]==0) {
    //         res+=" ";
    //         start++;
    //     }
    //     for(int i=start; i<spaces.size(); i++){
    //         res = res + s.substr(index,spaces[i]-index) + " ";
    //         index = spaces[i];
    //     }
    //     res = res + s.substr(index,s.size()-index);

    //     return res;
    // }
};

int main()
{
    Solution s;
    vector<int> spaces = {1, 5, 7, 9};
    cout << s.addSpaces("icodeinpython", spaces);
}