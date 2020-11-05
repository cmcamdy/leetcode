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
    vector<int> postorder(Node *root)
    {
        if (root == NULL)
            return res;
        BFS_LFN(root);
        return res;
    }
    void BFS_LFN(Node *root)
    {

        int len = root->children.size();
        for (int i = 0; i < len; i++)
        {
            BFS_LFN(root->children[i]);
        }
        res.push_back(root->val);
    }
};