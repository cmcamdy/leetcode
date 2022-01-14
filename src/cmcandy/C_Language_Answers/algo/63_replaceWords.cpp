#include <iostream>
#include <vector>
#include <map>
using namespace ::std;

class Tire
{
private:
    bool isWord;
    vector<Tire *> children;

public:
    Tire() : isWord(false), children(26, nullptr) {}
    void insert(const string &str)
    {
        Tire *node = this;
        for (auto &ch : str)
        {
            if (node->children[ch - 'a'] == nullptr)
            {
                node->children[ch - 'a'] = new Tire();
            }
            node = node->children[ch - 'a'];
        }
        node->isWord = true;
    }

    int countPreFixLen(const string &str)
    {
        Tire *node = this;
        int len = 0;
        for (auto &ch : str)
        {
            if (node->children[ch - 'a'] == nullptr)
            {
                return 0;
            }
            node = node->children[ch - 'a'];
            len++;
            if (node->isWord)
                return len;
        }
        return 0;
    }
};

// end() 函数返回一个指向当前vector末尾元素的下一位置的迭代器.要访问末尾元素,需要先将此迭代器减1。
// back() 函数返回当前vector最末一个元素的引用。

class Solution
{
public:
    string replaceWords(vector<string> &dictionary, string sentence)
    {
        // 就实现一个前缀树，然后判断一下
        Tire *root = new Tire();
        for (string &word : dictionary)
        {
            root->insert(word);
        }
        // 分割
        vector<string> words{""};
        for (auto &ch : sentence)
        {
            if (ch != ' ')
            {
                words.back().push_back(ch);
            }
            else
            {
                words.push_back("");
            }
        }
        // 处理
        vector<string> ret;
        for (auto &word : words)
        {
            int len = root->countPreFixLen(word);
            if (len == 0)
            {
                ret.emplace_back(word);
            }
            else
            {
                ret.push_back(word.substr(0, len));
            }
        }
        string ans{""};
        for (auto &word : ret)
        {
            ans += word;
            ans += " ";
        }
        ans.pop_back();
        return ans;
    }
};