#include <iostream>
#include <stack>
#include <string>
using namespace ::std;

/**
 * 
 * 
 * Valid Parenthesis String
    Description
    Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.

    The following rules define a valid string:

    Any left parenthesis '(' must have a corresponding right parenthesis ')'.
    Any right parenthesis ')' must have a corresponding left parenthesis '('.
    Left parenthesis '(' must go before the corresponding right parenthesis ')'.
    '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".

    Input
    The only line of input contains a string s. It is guaranteed that all symbols of s are

    ‘(‘, ‘)’ and ‘*”. The length of s does not exceed 
    Output
    In the only line print "True" if s is valid, and "NO" otherwise.

    Sample Input 1 
    ((*)
    Sample Output 1
    True
 **/

int main(int argc, char const *argv[])
{
    /* code */
    // string s = "(((((*(()((((*((**(((()()*)()()()*((((**)())*)*)))))))(())(()))())((*()()(((()((()*(())*(()**)()(())";
    string s;
    cin >> s;
    // cout<<s;
    int len = s.size();
    stack<int> star, left;
    for (int i = 0; i < len; i++)
    {
        if (s[i] == '*')
        {
            star.push(i);
        }
        else if (s[i] == '(')
        {
            left.push(i);
        }
        else
        {
            if (!left.empty())
            {
                left.pop();
            }
            else if (!star.empty())
            {
                star.pop();
            }
            else
            {
                cout << "NO";
                return 0;
            }
        }
    }
    int le, st;
    while (!left.empty() && !star.empty())
    {
        le = left.top();
        st = star.top();
        if (st < le)
        {
            cout << "NO";
            return 0;
        }
        left.pop();
        star.pop();
    }
    if(left.empty()) cout<<"True";
    else{
        cout<<"NO";
    }
    return 0;
}
