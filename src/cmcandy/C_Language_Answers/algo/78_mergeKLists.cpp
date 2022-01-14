#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace ::std;

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
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return merge(lists,0,lists.size()-1);
    }
    ListNode* merge(vector<ListNode*>& lists,int left, int right){
        if(left>right) return nullptr;
        else if(left==right) return lists[left];
        int mid = (left+right)/2;
        ListNode *lleft = merge(lists,left,mid), *lright = merge(lists,mid+1,right);
        
        ListNode *tmpHead = new ListNode(-1);
        ListNode *tmp = tmpHead;

        while(lleft!=nullptr && lright !=nullptr){
            if(lleft->val>lright->val) {
                tmp->next = lright;
                tmp = tmp->next;
                lright = lright->next;
            }else{
                tmp->next = lleft;
                tmp = tmp->next;
                lleft = lleft->next;
            }
        }
        if(lleft!=nullptr)tmp->next = lleft;
        else tmp->next = lright;
        return tmpHead->next;
    }
};
ListNode* makeList(vector<int> nums){
    ListNode *tmpHead = new ListNode(-1);
    for(int i=nums.size()-1; i>=0; i--){
        ListNode *tmp = new ListNode(nums[i],tmpHead->next);
        tmpHead->next = tmp;
    }
    return tmpHead->next;
}
int main(){
    vector<vector<int>> nums = {{1,4,5},{1,3,4},{2,6}};
    vector<ListNode*> lists;
    for(int i=0; i<nums.size(); i++){
        lists.push_back(makeList(nums[i]));
    }
    Solution s;
    s.mergeKLists(lists);
    cout<<"hello"<<endl;
}