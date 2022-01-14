#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string.h>
#include <algorithm>
using namespace ::std;

class Trie
{ //先构造一个字典树，用来存前缀单词
private:
public:
    Trie *children[26];
    bool isword;
    Trie()
    {
        memset(children, 0, sizeof(children));
        isword = false;
    }

    void insert(string &word)
    {
        Trie *node = this;
        for (auto tmp : word)
        {
            if (node->children[tmp - 'a'] == NULL)
                node->children[tmp - 'a'] = new Trie();
            node = node->children[tmp - 'a'];
        }
        node->isword = true;
    }
};

class Solution
{
private:
    int res = 0;

public:
    int minimumLengthEncoding(vector<string> words)
    {
        Trie *source = new Trie();
        for (auto tmp : words)
        {
            reverse(tmp.begin(), tmp.end());
            source->insert(tmp);
        }
        dfs(source, 1);
        return res;
    }

    void dfs(Trie *root, int count)
    {
        bool isLeaf = true;
        for (Trie *child : root->children)
        {
            if (child != NULL)
            {
                isLeaf = false;
                dfs(child, count + 1);
            }
        }
        if (isLeaf) //也就是没有子节点时，才把计数值加到总结果
                    //因为相同后缀的word，都终结于最后一个字母，只要一个“#”。
                    //而这个一个“#”的计数，在主函数传入dfs时，初始值为1，已经算上了。
            res += count;
    }
};