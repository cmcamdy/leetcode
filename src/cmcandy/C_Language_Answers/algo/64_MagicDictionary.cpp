#include <iostream>
#include <vector>
#include <map>
using namespace ::std;

class Tire
{
public:
    bool isWord;
    vector<Tire *> children;
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
};
class MagicDictionary
{
private:
    Tire *root;

public:
    /** Initialize your data structure here. */
    MagicDictionary()
    {
        root = new Tire();
    }

    void buildDict(vector<string> dictionary)
    {
        // root->insert()
        for (auto &word : dictionary)
        {
            root->insert(word);
        }
    }
    bool searchImpl(string str, int start, bool tolerate, Tire *node)
    {
        if (!node->isWord && str.size() == start)
            return false;
        else if (node->isWord && str.size() == start && !tolerate)
            return true;

        for (int j = 0; j < 26; j++)
        {
            if (node->children[j] != nullptr)
            {
                bool jud = false;
                if (str[start] - 'a' == j)
                {
                    jud = searchImpl(str, start + 1, tolerate, node->children[j]);
                }
                else
                {
                    if (!tolerate)
                        continue;
                    jud = searchImpl(str, start + 1, false, node->children[j]);
                }
                if (jud)
                    return true;
            }
        }
        return false;
    }
    bool search(string searchWord)
    {
        return searchImpl(searchWord, 0, true, root);
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */
int main()
{
    // vector<string> list = {"hello","hallo","leetcode","judge", "judgg"};
    // vector<string> list = {"hello","leetcode"};
    // MagicDictionary *magic = new MagicDictionary();
    // magic->buildDict(list);
    // cout<<magic->search("hello");
    // cout<<magic->search("qweasd");
    // cout<<magic->search("hhllo");

    vector<string> list = {"a", "b"};
    MagicDictionary *magic = new MagicDictionary();
    magic->buildDict(list);
    cout << magic->search("ab");
}