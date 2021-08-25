# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        head = ListNode()
        index = head
        while l1 is not None and l2 is not None:
            if l1.val <= l2.val:
                index.next = l1
                l1 = l1.next
            else:
                index.next = l2
                l2 = l2.next
            index = index.next

        if l1 is not None:
            index.next = l1
        if l2 is not None:
            index.next = l2
        return head.next
