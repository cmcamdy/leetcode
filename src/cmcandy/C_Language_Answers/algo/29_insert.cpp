class Node
{
public:
    int val;
    Node *next;

    Node() {}

    Node(int _val)
    {
        val = _val;
        next = nullptrptr;
    }

    Node(int _val, Node *_next)
    {
        val = _val;
        next = _next;
    }
};
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = nullptrptr;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution
{
public:
    Node *insert(Node *head, int insertVal)
    {
        if (head == NULL)
        {
            head = new Node(insertVal);
            head->next = head;
            return head;
        }
        else
        {
            Node *tmp = head, *insertNode = new Node(insertVal);
            //圈数
            int count = tmp->val > insertVal ? 1 : 0;
            // cout<<count;
            while ((tmp->val <= tmp->next->val && tmp->next != head) || count == 1)
            {
                if (tmp->val <= insertVal && tmp->next->val >= insertVal)
                {
                    insertNode->next = tmp->next;
                    tmp->next = insertNode;
                    return head;
                }
                tmp = tmp->next;
                if (tmp == head)
                    count--;
            }
            insertNode->next = tmp->next;
            tmp->next = insertNode;
            return head;
        }
    }
    // 这个版本简洁
    Node *insert2(Node *head, int insertVal)
    {
        if (head == nullptr)
        {
            head = new Node(insertVal);
            head->next = head;
            return head;
        }
        auto cur = head;
        while (cur->next != head)
        {
            if ((cur->val <= insertVal) ^ (cur->next->val >= insertVal) ^ (cur->next->val >= cur->val))
                break;
            cur = cur->next;
        }
        cur->next = new Node(insertVal, cur->next);
        return head;
    }
};