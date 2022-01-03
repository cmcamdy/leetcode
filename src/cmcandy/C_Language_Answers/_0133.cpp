#include <iostream>
#include <vector>
#include <map>

using namespace ::std;
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};
class Solution
{
public:
    map<Node *, Node *> m;
    Node *cloneGraph(Node *node)
    {
        if (node == nullptr)
            return nullptr;
        Node *cpNode = new Node(node->val);
        m[node] = cpNode;
        clone(node, cpNode);
        return cpNode;
    }
    void clone(Node *node, Node *cpNode)
    {
        vector<Node *> neighbors;
        for (auto &neighbor : node->neighbors)
        {
            Node *tmp;
            if (m.find(neighbor) != m.end())
                tmp = m[neighbor];
            else
            {
                tmp = new Node(neighbor->val);
                m[neighbor] = tmp;
                clone(neighbor, tmp);
            }
            neighbors.push_back(tmp);
        }
        cpNode->neighbors = neighbors;
    }
};