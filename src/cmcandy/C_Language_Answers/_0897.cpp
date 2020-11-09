#include <iostream>
#include <string>
#include <vector>
using namespace ::std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    vector<TreeNode *> arr;
    void BFS_M(TreeNode *root)
    {
        if (root == NULL)
            return;
        else
        {
            BFS_M(root->left);
            arr.push_back(root);
            BFS_M(root->right);
        }
    }
    TreeNode *increasingBST(TreeNode *root)
    {
        BFS_M(root);
        int len = arr.size();
        if (len == 0 || len == 1)
            return root;
        cout << len << endl;
        for (int i = 0; i < len - 1; i++)
        {
            cout << i << "   " << arr[i]->val << endl;
            arr[i]->left = NULL;
            arr[i]->right = arr[i + 1];
        }
        return arr[0];
    }
};