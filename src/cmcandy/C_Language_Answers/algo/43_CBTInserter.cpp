/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <queue>
#include <iostream>
using namespace ::std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class CBTInserter
{
public:
    TreeNode *head;
    queue<TreeNode *> q;
    CBTInserter(TreeNode *root)
    {
        q.push(root);
        head = root;
        while (q.front()->left != nullptr)
        {
            q.push(q.front()->left);
            if (q.front()->right != nullptr)
            {
                q.push(q.front()->right);
                q.pop();
            }
            else
            {
                break;
            }
        }
    }

    int insert(int v)
    {
        TreeNode *newNode = new TreeNode(v);
        q.push(newNode);
        int val = q.front()->val;
        if (q.front()->left == nullptr)
        {
            q.front()->left = newNode;
        }
        else
        {
            q.front()->right = newNode;
            q.pop();
        }
        return val;
    }

    TreeNode *get_root()
    {
        return head;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */