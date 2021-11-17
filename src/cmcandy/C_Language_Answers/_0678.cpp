#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace ::std;
class Solution
{
public:
    bool checkValidString_fail(string s)
    {
        int numStar = 0, numLeft = 0;
        int len = s.size();

        for (int i = 0; i < len; i++)
        {
            if (s[i] == '*')
                numStar++;
            else if (s[i] == '(')
                numLeft++;
            else
            {
                //此处都是）的情况，优先去numLeft
                if (numLeft > 0)
                    numLeft--;
                else if (numStar > 0)
                    numStar--;
                else
                    return false;
            }
        }
        return numStar >= numLeft ? true : false;
    }

    bool checkValidString_office(string s)
    {
        stack<int> leftStack;
        stack<int> asteriskStack;
        int n = s.size();

        for (int i = 0; i < n; i++)
        {
            char c = s[i];
            if (c == '(')
            {
                leftStack.push(i);
            }
            else if (c == '*')
            {
                asteriskStack.push(i);
            }
            else
            {
                if (!leftStack.empty())
                {
                    leftStack.pop();
                }
                else if (!asteriskStack.empty())
                {
                    asteriskStack.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        //这里一个一个判断的原因是防止出现这种：*（  情况，这样的话即使是一对也不能算，因此，不能够只用简单的int表示数量，二是要记录每个*和（出现的位置，不一定用stack，用数组也可以模拟
        while (!leftStack.empty() && !asteriskStack.empty())
        {
            int leftIndex = leftStack.top();
            leftStack.pop();
            int asteriskIndex = asteriskStack.top();
            asteriskStack.pop();
            if (leftIndex > asteriskIndex)
            {
                return false;
            }
        }
        return leftStack.empty();
    }
};
int main(int argc, char const *argv[])
{

    Solution s;
    s.checkValidString_office("(((((*(()((((*((**(((()()*)()()()*((((**)())*)*)))))))(())(()))())((*()()(((()((()*(())*(()**)()(())");
    return 0;
}
