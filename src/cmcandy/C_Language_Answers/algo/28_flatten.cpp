

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
class Node
{
public:
    int val;
    Node *prev;
    Node *next;
    Node *child;
};

class Solution
{
public:
    Node *flatten(Node *head)
    {
        //递归
        if (head == nullptr)
            return head;
        flattenImpl(head);
        return head;
    }
    Node *flattenImpl(Node *head)
    {
        while (head->next != nullptr or head->child != nullptr)
        {
            if (head->child == nullptr)
                head = head->next;
            else
            {
                Node *tmp = head->next, *tmp2 = nullptr;
                head->next = head->child;
                head->next->prev = head;
                tmp2 = flattenImpl(head->child);
                head->child = nullptr;
                tmp2->next = tmp;
                if (tmp != nullptr)
                {
                    tmp->prev = tmp2;
                    head = tmp;
                }
                else
                {
                    return tmp2;
                }
            }
        }
        return head;
    }
};