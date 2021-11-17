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
#include <vector>
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
class Solution
{
public:
    vector<TreeNode *> generateTrees(int n)
    {

        return buildTree(1, n);
    }
    vector<TreeNode *> buildTree(int start, int end)
    {
        //遍历，以某点当作root继续
        vector<TreeNode *> res;
        if (start == end)
        {
            //只有一个节点，那么这是叶子
            TreeNode *t = new TreeNode(start);
            res.push_back(t);
            return res;
        }
        else if (start < end)
        {
            for (int i = start; i <= end; i++)
            {
                // TreeNode *root = new TreeNode(i);
                vector<TreeNode *> left = buildTree(start, i - 1);
                vector<TreeNode *> right = buildTree(i + 1, end);
                if (left.size() == 0)
                {
                    for (int n = 0; n < right.size(); n++)
                        res.push_back(new TreeNode(i, nullptr, right[n]));
                }
                else if (right.size() == 0)
                {
                    for (int m = 0; m < left.size(); m++)
                        res.push_back(new TreeNode(i, left[m], nullptr));
                }
                else
                    for (int m = 0; m < left.size(); m++)
                    {
                        for (int n = 0; n < right.size(); n++)
                        {
                            //构造树
                            res.push_back(new TreeNode(i, left[m], right[n]));
                        }
                    }
            }
        }
        return res;
    }
};
int main(int argc, char const *argv[])
{
    Solution s;
    // vector<TreeNode *> res = s.buildTree(1, 1);
    // cout << res[0]->val;
    vector<TreeNode *> res = s.generateTrees(3);

    return 0;
}
