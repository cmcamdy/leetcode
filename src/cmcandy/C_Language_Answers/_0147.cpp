#include <iostream>
#include <vector>

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
    ListNode *insertionSortList(ListNode *head)
    {
        ListNode *tmp1 = head, *tmp2 = head, *tmp3;
        if (tmp1 == NULL)
            return head;
        while (tmp1 != NULL && tmp1->next != NULL)
        {
            tmp3=head;
            while (tmp3 != NULL)
            {
                cout << tmp3->val;
                tmp3 = tmp3->next;
            }
            cout<<endl;
            tmp2 = head;
            //当前值最小时，直接放到首部
            if (tmp2->val > tmp1->next->val)
            {
                // cout<<tmp2->val<<"  ____ "<<endl;
                tmp3 = tmp1->next;
                tmp1->next = tmp3->next;
                tmp3->next = tmp2;
                head = tmp3;
            }
            else if (tmp1 == head||tmp1->val<=tmp1->next->val)
            {
                tmp1 = tmp1->next;
            }
            else
            {
                while (tmp2 != tmp1)
                {
                    cout << tmp2->val << tmp1->next->val << endl;
                    //遇到的第一个小于该数的节点，插入
                    if (tmp2->next->val > tmp1->next->val)
                    {
                        tmp3 = tmp1->next;
                        tmp1->next = tmp3->next;
                        tmp3->next = tmp2->next;
                        tmp2->next = tmp3;
                        break;
                    }
                    else
                    {
                        tmp2 = tmp2->next;
                    }
                }
                
            }
        }
        return head;
    }
};
int main(int argc, char const *argv[])
{
    Solution s;
    // vector<int> l{-1, 5, 3, 4, 0};
    // vector<int> l{3,2,4};
    vector<int> l(10,0);
    int len = l.size();
    ListNode *head = new ListNode(l[len - 1]);
    for (int i = len - 2; i >= 0; i--)
    {
        // cout<<l[i]<<endl;
        ListNode *tmp = new ListNode(l[i]);
        tmp->next = head;
        head = tmp;
    }

    // while(head!=NULL){
    //     cout<<head->val<<endl;
    //     head = head->next;
    // }
    s.insertionSortList(head);
}
