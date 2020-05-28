package cmcandy.Java_Language_Answers;

/**
 * Created by CHEN on 2020/4/20.
 */
public class _0019 {
    /**
     * Definition for singly-linked list.
     * public class ListNode {
     * int val;
     * ListNode next;
     * ListNode(int x) { val = x; }
     * }
     */
    static class ListNode {
        int val;
        ListNode next;

        ListNode(int x) {
            val = x;
        }
    }

    static class Solution {
        public ListNode removeNthFromEnd(ListNode head, int n) {
            int length = 0;
            ListNode temp_head = head;
            ListNode temp_tail = head;

            while (temp_tail.next != null) {
                temp_tail = temp_tail.next;
                if (length < n) {
                    length++;
                } else if (length >= n) {
                    temp_head = temp_head.next;
                }
            }
            if (length == n - 1) {
                //说明删除的是头部节点
                return temp_head.next;
            } else if (length >= n) {
                //说明删除的是非头部节点
                temp_head.next = temp_head.next.next;
            }
            return head;
        }
    }
}
