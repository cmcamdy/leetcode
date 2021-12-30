

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
#include <vector>
using namespace ::std;
#define MAX_INT (((unsigned int)(-1)) >> 1)
#define MIN_INT MAX_INT + 1
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> res;
        if (root == nullptr)
            return res;
        int count = 1, next_line = 0;

        queue<TreeNode *> q;
        res.push_back(root->val);
        q.push(root);
        while (!q.empty() && count != 0)
        {
            TreeNode *tmp = q.front();
            q.pop();
            if (tmp->right != nullptr)
            {
                next_line++;
                q.push(tmp->right);
            }
            if (tmp->left != nullptr)
            {
                next_line++;
                q.push(tmp->left);
            }
            count--;
            if (count == 0)
            {
                if (next_line == 0)
                    return res;
                res.push_back(q.front()->val);
                count = next_line;
                next_line = 0;
            }
        }
        return res;
    }
};