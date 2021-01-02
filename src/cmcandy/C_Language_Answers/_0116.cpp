#include <iostream>
#include <math.h>
#include <vector>
using namespace ::std;
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
class Solution
{
public:
    Node *connect(Node *root)
    {
        //考察广度优先遍历
        vector<Node *> lis;
        Node *tmp = new Node(-1);
        lis.push_back(root);
        lis.push_back(tmp);

        Node *now,*next;
        while (!lis.empty()){



        }
    }
};