#include <iostream>
#include <vector>
using namespace ::std;

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
    int rob(TreeNode *root)
    {
        // 可以试着将 val改成dp：意义是该子树能偷的最大数目
        int money[2]={0,0};
        robTree(root,money);
        cout<<money[0]<<money[1]<<endl;
        return max(money[0],money[1]);
    }
    void robTree(TreeNode *root, int* money)
    {
        if(root == nullptr) return;
        int leftMoney[2] = {0,0},rightMoney[2] = {0,0};
        
        robTree(root->left,leftMoney);
        robTree(root->right, rightMoney);
        //当前节点不可以要
        money[1] = leftMoney[0]+rightMoney[0];
        //当前节点可以要
        money[0] = max(money[1], root->val+ leftMoney[1]+rightMoney[1]);
    }
};
int main(){
    Solution s;
    s.rob(nullptr);
}