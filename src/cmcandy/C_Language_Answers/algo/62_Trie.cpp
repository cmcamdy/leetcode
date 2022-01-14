#include <iostream>
#include <vector>
#include <map>
using namespace ::std;


class Trie
{
public:
    struct TreeNode
    {
        char val;
        vector<TreeNode *> children;
        TreeNode(char x) : val(x) {
        }
    };
    /** Initialize your data structure here. */
    TreeNode *root = new TreeNode('1');
    Trie()
    {
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        bool findChar = false;
        TreeNode *tmp = root;
        for (int i = 0; i < word.size(); i++)
        {
            int len = tmp->children.size();
            for (int j = 0; j < len; j++)
            {
                if (tmp->children[j]->val == word[i])
                {
                    tmp = tmp->children[j];
                    findChar = true;
                    break;
                }
            }
            if (!findChar)
            {
                TreeNode *newNode = new TreeNode(word[i]);
                tmp->children.push_back(newNode);
                tmp = tmp->children[len];
            }
            else
                findChar = false;
        }
        tmp->children.push_back(new TreeNode('1'));
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        bool findChar = false;
        TreeNode *tmp = root;
        for (int i = 0; i < word.size(); i++)
        {
            int len = tmp->children.size();
            for (int j = 0; j < len; j++)
            {
                if (tmp->children[j]->val == word[i])
                {
                    tmp = tmp->children[j];
                    findChar = true;
                    break;
                }
            }
            if (!findChar)
            {
                return false;
            }
            else
                findChar = false;
        }

        for(int i=0; i<tmp->children.size(); i++){
            if(tmp->children[i]->val == '1') return true;
        }
        return false;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        bool findChar = false;
        TreeNode *tmp = root;
        for (int i = 0; i < prefix.size(); i++)
        {
            int len = tmp->children.size();
            for (int j = 0; j < len; j++)
            {
                if (tmp->children[j]->val == prefix[i])
                {
                    tmp = tmp->children[j];
                    findChar = true;
                    break;
                }
            }
            if (!findChar)
            {
                return false;
            }
            else
                findChar = false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
int main()
{
    Trie *t = new Trie();
    t->insert("apple");
    cout << t->search("apple");
    cout << t->search("app");
    cout << t->startsWith("app");
    t->insert("app");
    cout << t->search("app");
}