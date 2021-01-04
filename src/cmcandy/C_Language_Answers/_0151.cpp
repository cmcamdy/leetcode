#include <iostream>
#include <string.h>
#include <algorithm>

using namespace ::std;

class Solution
{
public:
    string reverseWords(string s)
    {
        //翻转两次也是可以的
        //第一次整体反转
        reverse(s.begin(), s.end());
        int len = s.size();
        //第二次部分反转
        int left = 0, blank = 0, jud = 0;
        for (int i = 0; i < len; i++)
        {
            if (s[i] != ' ' && jud == 0)
            {
                jud = 1;
            }
            else if (s[i] == ' ' && jud == 0)
            {
                //记录下空格，用于下一个left的取值
                blank++;
            }
            //如果时空格，且之前是由字符的，那么表示单词末尾
            else if (s[i] == ' ' && jud == 1)
            {
                reverse(s.begin() + left, s.begin() + i);
                jud = 0;
                left = i + 1 - blank;
            }
        }
        //防止最后不是空格的情况
        if (s[len - 1] != ' ')
            reverse(s.begin() + left, s.end());
        //消除重复空格
        for (int i = len - 1; i > 0; i--)
        {
            if (s[i] != ' ')
            {
                //如果不是‘ ’，那么说明到底了，截断后面部分
                return s.substr(0, i + 1);
            }
        }
        return s;
    }
};