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
    int maxDepth(TreeNode *root)
    {
        int depth = 0;
        if (root == NULL)
            return 0;
        if (root->left == NULL && root->right == NULL)
            return 1;
        else
            return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

// void test(TreeNode *root){
//     TreeNode node = TreeNode(2);
//     root = &node;
//     cout<<(root->val)<<endl;
// }
// int main(int argc, char const *argv[])
// {
//     TreeNode node = TreeNode(1);
//     TreeNode* point = &node;
//     cout<<(point->val)<<endl;

//     test(point);
//     cout<<(point->val);
//     return 0;
// }
