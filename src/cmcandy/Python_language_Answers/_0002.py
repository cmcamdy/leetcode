# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        carry = 0
        tmp = 0
        res = None
        now = None
        while (l1 is not None or l2 is not None or carry !=0):
            if l1 is not None and l2 is not None:
                tmp = l1.val + l2.val + carry
                l1 = l1.next
                l2 = l2.next
            elif l1 is None and l2 is None:
                tmp = carry
                if tmp == 0:
                    return res
            elif l1 is not None:
                tmp = l1.val + carry 
                l1 = l1.next
            elif l2 is not None:
                tmp = l2.val + carry
                l2 = l2.next
            print(tmp)
            if tmp >= 10:
                tmp -= 10
                carry = 1
            else:
                carry = 0
            if res is None:
                res = ListNode(tmp, None)
                now = res
            else:
                now.next = ListNode(tmp, None)
                now = now.next
        return res 
