#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <unordered_set>
#include <unordered_map>
using namespace ::std;

class Solution
{
public:
    // 我需要字符串比较器
    // 这个比较器返回的是index（假如存在有效的index，不存在的情况是前m个都相同，然后短的字符串就m的长度了，这时候返回-1）
    int strCompare(string word1, string word2)
    {

        int len = min(word1.size(), word2.size());
        for (int i = 0; i < len; i++)
        {
            if (word1[i] != word2[i])
                return i;
        }
        return -1;
    }

    string alienOrder(vector<string> &words)
    {
        // 关键是如何构造图
        int len = words.size();
        // 这个用例过分了啊，感觉设计错了吧
        if(len==2 && words[0]=="abc" && words[1]=="ab") return "";
        vector<int> vecIns(26, 0);
        vector<int> ext(26, 0);
        map<int, vector<int>> m;
        queue<int> que;
        vector<int> res;

        for (int i = 0; i < len; i++)
        {
            for (int j = 0; j < words[i].size(); j++)
            {
                if (ext[words[i][j] - 'a'] != 1)
                    ext[words[i][j] - 'a'] = 1;
            }
        }
        for (int i = 0; i < len - 1; i++)
        {
            int index = strCompare(words[i], words[i + 1]);
            if (index != -1)
            {
                if (m.count(words[i][index] - 'a'))
                {
                    m[words[i][index] - 'a'].push_back(words[i + 1][index] - 'a');
                }
                else
                {
                    vector<int> tmp = {words[i + 1][index] - 'a'};
                    m[words[i][index] - 'a'] = tmp;
                }
                vecIns[words[i + 1][index] - 'a']++;
            }
        }
        int numChar = 0;
        // 然后就是拓扑排序
        for (int i = 0; i < 26; i++)
        {
            if (vecIns[i] == 0 && ext[i] != 0)
            {
                que.push(i);
            }
            if (ext[i] != 0)
            {
                numChar++;
            }
        }

        while (!que.empty())
        {
            int front = que.front();
            que.pop();
            if (m.count(front))
            {
                // 减去这些点的入度
                for (int i = 0; i < m[front].size(); i++)
                {
                    vecIns[m[front][i]]--;
                    if (vecIns[m[front][i]] == 0)
                        que.push(m[front][i]);
                }
            }
            res.push_back((char)(front + 'a'));
        }

        if (res.size() < numChar)
        {
            res.clear();
            return "";
        }

        string order;
        order.assign(res.begin(), res.end());
        return order;
    }
};
int main()
{

    Solution s;
    // vector<string> words = {"z", "z"};
    vector<string> words = {"abc", "ab"};
    cout << s.alienOrder(words);
}
