#include <iostream>
#include <string>
#include <vector>
using namespace ::std;
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};
class Solution
{
public:
    vector<int> res;
    vector<int> preorder(Node *root)
    {
        if (root == NULL)
            return res;
        BFS_NLF(root);
        return res;
    }
    void BFS_NLF(Node *root)
    {
        res.push_back(root->val);
        int len = root->children.size();
        for (int i = 0; i < len; i++)
        {
            BFS_NLF(root->children[i]);
        }
    }
};