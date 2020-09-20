#include <iostream>
#include <math.h>

using namespace ::std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution
{
public:
    bool isBalanced(TreeNode *root)
    {
        return funDepth(root) == -1 ? false : true;
    }

    int funDepth(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        if (root->left == NULL && root->right == NULL)
            return 1;
        else
        {
            int depthl = funDepth(root->left);
            int depthr = funDepth(root->right);

            //如果平衡，则返回深度，否则返回-1
            if (depthr != -1 && depthl != -1 && abs(depthr - depthl) <= 1)
                return max(depthr, depthl) + 1;
            else
                return -1;
        }
    }
};