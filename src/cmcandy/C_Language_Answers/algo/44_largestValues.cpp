

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
    vector<int> largestValues(TreeNode *root)
    {
        vector<int> res;
        if (root == nullptr)
            return res;
        int count = 1, next_line = 0;
        queue<TreeNode *> q;
        q.push(root);
        int tmp_max = MIN_INT;
        while (!q.empty() && count != 0)
        {
            TreeNode *tmp = q.front();
            q.pop();
            if (tmp->left != nullptr)
            {
                next_line++;
                q.push(tmp->left);
            }
            if (tmp->right != nullptr)
            {
                next_line++;
                q.push(tmp->right);
            }
            count--;
            tmp_max = max(tmp_max, tmp->val);
            if (count == 0)
            {
                res.push_back(tmp_max);
                tmp_max = MIN_INT;
                count = next_line;
                next_line = 0;
            }
        }
        return res;
    }
};