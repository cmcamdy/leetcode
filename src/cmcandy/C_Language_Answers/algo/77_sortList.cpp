

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode *sortList(ListNode *head)
    {
        return mergeSort(head);
    }

    ListNode *mergeSort(ListNode *head){
        
        //单节点和空节点的情况
        if(head==nullptr || head->next == nullptr) return head;
        // 找到中心节点
        ListNode *tmpHead = new ListNode(-1,head);
        ListNode *fast = tmpHead, *slow = tmpHead;
        while(fast!=nullptr && fast->next !=nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *left = head, *right = slow->next;
        slow->next = nullptr;
        //  保证子序列有序
        left = mergeSort(left);
        right = mergeSort(right);
        ListNode *tmp = tmpHead;

        while(left!=nullptr && right !=nullptr){
            if(left->val>right->val) {
                tmp->next = right;
                tmp = tmp->next;
                right = right->next;
            }else{
                tmp->next = left;
                tmp = tmp->next;
                left = left->next;
            }
        }
        if(left!=nullptr)tmp->next = left;
        else tmp->next = right;
        return tmpHead->next;
    }
};
int main(){
    ListNode *tmp = new ListNode(3);
    ListNode *tmp1 = new ListNode(1,tmp);
    ListNode *tmp2 = new ListNode(2,tmp1);
    ListNode *tmp3 = new ListNode(4,tmp2);

    Solution s;
    s.sortList(tmp3);
    

}