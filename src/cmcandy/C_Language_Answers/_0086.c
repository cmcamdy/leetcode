# include <stdio.h>
# include <stdlib.h>

//未完成
struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode* partition(struct ListNode* head, int x){
    struct ListNode *less = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *more = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *equal = (struct ListNode*)malloc(sizeof(struct ListNode));
    
    //定义仨指针
    struct ListNode* pless = less;
    struct ListNode* pmore = more;
    struct ListNode* pequal = equal;
    struct ListNode* plist = head;

    while(plist!=NULL){
        if(plist->val<x){
            pless->next = plist;
            plist = plist->next;
            pless = pless->next;
            pless->next = NULL;
        }else if(plist->val>x){
            pmore->next = plist;
            pmore = pmore->next;
            pmore = pmore->next;
            pmore->next = NULL;
        }else if(plist->val==x){
            pequal->next = plist;
            pequal = pequal->next;
            pequal = pequal->next;
            pequal->next = NULL;
        }
    }
    
    if(pequal->next!=NULL){
        //==more没有
        pless->next = equal->next;
    }
    if(more->next!=NULL){
        //==more没有
        pequal->next = more->next;
    }
    
    return less->next;
}
int main(int argc, char const *argv[])
{
    struct ListNode *head =(struct ListNode*)malloc(sizeof(struct ListNode));
    head->val = 1;
    struct ListNode *list =(struct ListNode*)malloc(sizeof(struct ListNode));
    list->val = 4;
    head->next = list;
    struct ListNode *list2 =(struct ListNode*)malloc(sizeof(struct ListNode));
    list2->val = 3;
    list->next = list2;
    list = list ->next;
    list2 =(struct ListNode*)malloc(sizeof(struct ListNode));
    list2->val = 2;
    list->next = list2;
    list = list ->next;
    list2 =(struct ListNode*)malloc(sizeof(struct ListNode));

    list2->val = 5;
    list->next = list2;
    list = list ->next;


    list2 =(struct ListNode*)malloc(sizeof(struct ListNode));
    list2->val = 2;
    list->next = list2;
    list = list ->next;

    partition(head,3);
    return 0;
}
