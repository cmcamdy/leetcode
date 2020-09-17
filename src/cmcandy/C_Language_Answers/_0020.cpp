#include <iostream>
#include <string>
#include <stack>

using namespace ::std;

class Solution
{
public:
    bool isValid(string s)
    {   
        int len = s.size();
        stack<char> st;
        for (int i = 0; i < len; i++)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                st.push(s[i]);
            }
            else if (s[i] == ')' || s[i] == '}' || s[i] == ']')
            {   
                
                if (st.empty()||(st.top() != s[i]-1&&st.top() != s[i]-2))
                {
                    return false;
                }
                else
                {
                    st.pop();
                }
            }
        }
        return st.empty();
    }
};
