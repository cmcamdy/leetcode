#include <iostream>
#include <stack>
#include <vector>
#include <map>
using namespace ::std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
public:
    vector<int> nextLargerNodes(ListNode *head)
    {

        stack<int> s;
        stack<int> index;
        int count = 0;
        ListNode *tmp = head;
        while (tmp != NULL)
        {
            tmp = tmp->next;
            count++;
        }
        vector<int> res(count, 0);
        tmp = head;
        count = 0;
        while (tmp != NULL)
        {
            while ((!s.empty()) && s.top() < tmp->val)
            {
                res[index.top()] = tmp->val;
                s.pop();
                index.pop();
            }
            s.push(tmp->val);
            index.push(count);
            count++;
            tmp = tmp->next;
        }
        return res;
    }
};