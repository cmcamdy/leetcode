from typing import List


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        head = ListNode()
        if len(lists) == 0:
            return None
        now = head
        self.init = []
        for index in range(len(lists)):
            if lists[index] is not None:
                self.init.append([lists[index].val, index])
        nowIndex = 0
        length = len(self.init)
        # 优化：这里改成自定义排序就行了，类似于胜者树的思想吧，只不过改成维护一个数组
        self.init.sort()
        while nowIndex < length:
            now.next = lists[self.init[nowIndex][1]]
            now = now.next
            lists[self.init[nowIndex][1]] = lists[self.init[nowIndex][1]].next
            if lists[self.init[nowIndex][1]] is None:
                nowIndex += 1
            else:
                self.init[nowIndex][0] = lists[self.init[nowIndex][1]].val
            self.mySort(nowIndex, length)
        return head.next

    def mySort(self, start=0, end=0):
        '''
            维护队列用的sort主要是为了找到新的元素的位置,也可以用二分法找
            实际上胜者树可能更好，但是维护队列可能更简单
        '''
        if start == end:
            return
        tmp = self.init[start]
        for index in range(start + 1, end):
            if self.init[index][0] >= tmp[0]:
                self.init[index - 1] = tmp
                return
            else:
                self.init[index - 1] = self.init[index]
        self.init[end - 1] = tmp
        return
