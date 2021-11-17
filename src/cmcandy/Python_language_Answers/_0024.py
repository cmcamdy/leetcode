# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:

        tmpHead = ListNode(next=head)
        tmp = tmpHead
        while tmp.next is not None and tmp.next.next is not None:
            tmp.next = self.swapPair(tmp.next)
            tmp = tmp.next.next
        return tmpHead.next

    def swapPair(self, head: ListNode):
        sec = head.next
        head.next = sec.next
        sec.next = head
        return sec