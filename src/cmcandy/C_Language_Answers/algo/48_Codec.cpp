#include <queue>
#include <iostream>
#include <vector>
using namespace ::std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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
class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        if (root == nullptr)
            return "X";
        else
        {
            return "(" + serialize(root->left) + ")" + to_string(root->val) + "(" + serialize(root->right) + ")";
        }
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        // cout<<data;
        int len = data.size();
        int ptr = 0;
        return parse(data, ptr);
    }

   
    TreeNode* parse(string &data, int &ptr){
        // cout<<data;
        if(data[ptr]=='X'){
            ptr++;
            return nullptr;
        }
        TreeNode* root = new TreeNode(-1);
        // 首先左
        root->left = parseSubtree(data,ptr);
        int num = 0;
        int symbol = 1;
        if(data[ptr]=='-') {
            symbol = -1;
            ptr++;
        }
        while(data[ptr]<='9' && data[ptr]>='0'){
            num = num*10+data[ptr]-'0';
            ptr++;
        }
        root->val = symbol*num;
        // 然后右
        root->right = parseSubtree(data,ptr);
        return root;
    }
    TreeNode* parseSubtree(string &data, int &ptr){
        // (
        ptr++;
        TreeNode* root = parse(data,ptr);
        // )
        ptr++;
        return root;
    }

    // Decodes your encoded data to tree.
    // 我这里自顶向下了，复杂度太高，搞一个自底向上
    // 但是后来测试发现，时间并没有差别，之前用时高是因为string 直接传值，导致每次调用都得复制一下，所以改成传地址就OK了
    TreeNode *deserialize2(string data)
    {
        cout << data;
        int len = data.size();
        return deserialize2Impl(data, 0, len);
    }

    TreeNode *deserialize2Impl(string &data, int start, int end)
    {
        int stack = 0;
        if (data[start] == 'X')
            return nullptr;
        for (int i = start; i < end; i++)
        {
            if (data[i] == '(')
                stack++;
            else if (data[i] == ')')
                stack--;
            if (stack == 0)
            {
                int num = 0;
                int symbol = 1;
                if (data[++i] == '-')
                {
                    symbol = -1;
                    i++;
                }
                TreeNode *root = new TreeNode(-1);
                root->left = deserialize2Impl(data, start + 1, i - 1);
                while (i < end && data[i] != '(')
                {
                    num = 10 * num + data[i] - '0';
                    i++;
                }
                root->val = symbol * num;
                root->right = deserialize2Impl(data, i + 1, end - 1);
                return root;
            }
        }
        return nullptr;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

int main()
{

    Codec c;
    // TreeNode *res = c.deserialize("((X)2(X))1(((X)4(X))3((X)5(X)))((X)2(X))1(((X)4(X))3((X)5(X)))");
    TreeNode *res = c.deserialize("((X)-7(X))4((((((X)0((X)-1(X)))6(((X)-4(X))6(X)))9(X))-9((((X)5(X))-6(X))-7((((X)-2(X))9(X))-6(X))))-3(((X)-4(X))-3(X)))");
    // TreeNode *res = c.deserialize2("((X)-7(X))4((((((X)0((X)-1(X)))6(((X)-4(X))6(X)))9(X))-9((((X)5(X))-6(X))-7((((X)-2(X))9(X))-6(X))))-3(((X)-4(X))-3(X)))");
    
    return 0;
}