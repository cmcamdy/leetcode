/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    
    if(l1==NULL) return l2;
    else if(l2==NULL) return l1;
    struct ListNode* p;
    struct ListNode* head;
    if(l1->val<=l2->val){
        head = l1;
        l1 = l1->next;
    } else{
        head = l2;
        l2 = l2->next;
    }
    p  = head;
    while(l1!=NULL||l2!=NULL){
        if(l1==NULL) {
            p->next = l2;
            return head;
        }else if(l2 == NULL){
            p->next = l1;
            return head;
        }else{
            //二者都不为空

            if(l1->val<=l2->val){
                    p->next = l1;
                    l1 = l1->next;
                    p = p->next;
                } else{
                    p->next = l2;
                    l2 = l2->next;
                    p = p ->next;
                }
        }
    }
    return head;
}