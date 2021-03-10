#include <iostream>
#include <vector>

using namespace ::std;

class Solution
{
public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> res;
        return part(res, "", s, 0);
    }

    //判断回文
    bool judge(string s, int start, int end)
    {
        while (start < end)
        {
            if (s[start] == s[end])
            {
                start++;
                end--;
            }
            else
                return false;
        }
        return true;
    }
    //分支回溯
    vector<vector<string>> part(vector<vector<string>> last, string last_add, string &s, int start)
    {
        // 先更新last数组
        if (last_add != "")
        {
            if (last.size() == 0)
            {
                vector<string> tmp_add;
                tmp_add.push_back(last_add);
                last.push_back(tmp_add);
            }
            else
            {
                //字符非空，则先加上
                for (int i = 0; i < last.size(); i++)
                {
                    last[i].push_back(last_add);
                }
            }
        }
        

        //如果没，则开启下一轮
        vector<vector<string>> res;
        for (int i = start; i < s.size(); i++)
        {
            //判断是否是回文
            if (judge(s, start, i))
            {
                //如果是则进入下一级
                vector<vector<string>> tmp = part(last, s.substr(start, i - start + 1), s, i + 1);
                
                //然后加入列表
                res.insert(res.end(), tmp.begin(), tmp.end());
            }
            //不是则加长
        }
        //如果拆到底了，就返回更新的last
        if (start == s.size())
        {
            return last;
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<vector<string>> res = s.partition("abbab");
    return 0;
}
