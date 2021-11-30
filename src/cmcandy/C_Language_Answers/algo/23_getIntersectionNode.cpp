#include <iostream>
#include <string>
using namespace ::std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *tAhead = new ListNode(-1,headA), *tBhead = new ListNode(-1,headB);
        ListNode *tA = tAhead, *tB = tBhead;

        int lenA=0,lenB=0;
        while(tA->next!=NULL){
            lenA++;
            tA=tA->next;
        }
        while(tB->next!=NULL){
            lenB++;
            tB=tB->next;
        }
        tA = tAhead;
        tB = tBhead;
        if(lenA<lenB){
            for(int i=0; i<lenB-lenA; i++){
                tB = tB->next;
            }
        }else if(lenA>lenB){
            for(int i=0; i<lenA-lenB; i++){
                tA = tA->next;
            }
        }
        while(tA!=NULL){
            if(tA==tB){
                return tA;
            }
            tA = tA->next;
            tB = tB->next;
        }
        return NULL;
    }
};