# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        if head == None:
            return head
        cur = head
        i = k
        # 凑一凑可以反转列表的最后一个
        while i > 0 and cur != None:
            cur = cur.next
            i -= 1
        # 如果不够，直接返回head
        if i > 0: 
            return head
        # cur 是下一组的第一个
        # pre 是下一组反转完后的第一个
        pre = self.reverseKGroup(cur,k)
        i = k
        cur = head 
        # 本组反转
        while i > 0:
            tmp = cur.next
            cur.next = pre
            pre = cur
            cur = tmp
            i -= 1
        # 返回本组反转的后一个，也就是反转后的第一个
        return pre
