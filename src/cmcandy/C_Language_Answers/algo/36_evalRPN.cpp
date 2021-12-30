#include <iostream>
#include <string>
#include <vector>
// #include <stringstream>
#include <stack>
#include <sstream>
using namespace ::std;

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        int len = tokens.size();
        stack<int> s;
        
        for (int i = 0; i < len; i++)
        {
            if (tokens[i] != "*" && tokens[i] != "/" && tokens[i] != "+" && tokens[i] != "-")
            {
                //除了stringstream，还有一种转换方法
                s.push(stoi(tokens[i]));
                // stringstream ss;
                // int tmp;
                // ss << tokens[i];
                // ss >> tmp;
                // s.push(tmp);
            }
            else
            {
                int tmp1, tmp2;
                tmp1 = s.top();
                s.pop();
                tmp2 = s.top();
                s.pop();
                if (tokens[i] == "*")
                {
                    s.push(tmp2 * tmp1);
                }
                else if (tokens[i] == "/")
                {
                    s.push(tmp2 / tmp1);
                }
                else if (tokens[i] == "+")
                {
                    s.push(tmp2 + tmp1);
                }
                else if (tokens[i] == "-")
                {
                    s.push(tmp2 - tmp1);
                }
            }
        }
        return s.top();
    }
};
int main()
{
    vector<string> tokens = {"2", "1", "+", "3", "*"};
    Solution s;
    cout<<s.evalRPN(tokens);
}