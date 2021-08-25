# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        # 由题目给的条件可知，不必考虑链表不够长的问题

        fir = head
        sec = head
        for i in range(n):
            sec = sec.next
        if sec is None:
            return head.next
        while sec.next is not None:
            fir = fir.next
            sec = sec.next

        fir.next = fir.next.next
        return head
