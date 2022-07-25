#include <iostream>
#include <vector>
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

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
  ListNode *deleteDuplicates(ListNode *head) {

    if (head == nullptr)
      return head;
    // add 一个头节点
    ListNode *virHead = new ListNode(-101, head);

    // 只有当三个tmp都不一样的时候才向前走
    ListNode *tmp1 = virHead, *tmp2 = head, *tmp3 = head->next;
    while (tmp2 != nullptr && tmp3 != nullptr) {
      if (tmp1->val != tmp2->val && tmp2->val != tmp3->val) {
        if (tmp2->next == tmp3) {
          //向前
          tmp1 = tmp2;
          tmp2 = tmp3;
        } else {
          //删除tmp2
          tmp1->next = tmp3;
          tmp2 = tmp3;
        }
      }
      tmp3 = tmp3->next;
    }
    // 然后这里需要考虑到一个情况就是，3333null，那么我们就应该在出while
    if (tmp2->next != tmp3) {
      // 不能保留tmp2
      tmp1->next = tmp3;
    }
    return virHead->next;
  }
};

int main(){

    ListNode *virHead = new ListNode(-101);
    ListNode *tmp1=virHead, *tmp2;
    
    vector<int> nodes = {1,2,3,3,4,4,5};

    for(auto node : nodes){
        tmp2 = new ListNode(node);
        tmp1->next = tmp2;
        tmp1 = tmp1->next;
        tmp2 = tmp2->next;
    }
    Solution s;
    tmp2 = s.deleteDuplicates(virHead->next);
    cout<< "helloworld" << endl;

}