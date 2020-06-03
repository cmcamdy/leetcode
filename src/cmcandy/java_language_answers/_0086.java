package cmcandy.java_language_answers;

public class _0086 {
    /**
     * Definition for singly-linked list. public class ListNode { int val; ListNode
     * next; ListNode(int x) { val = x; } }
     */
    public class ListNode {
        int val;
        ListNode next;

        ListNode(int x) {
            val = x;
        }
    }

    class Solution {
        public ListNode partition(ListNode head, int x) {
            // xiao da
            ListNode small = new ListNode(-1);
            ListNode big = new ListNode(-1);

            ListNode pSmall = small;
            ListNode pBig = big;

            while (head != null) {
                if (head.val < x) {
                    pSmall.next = head;
                    pSmall = pSmall.next;
                } else {
                    pBig.next = head;
                    pBig = pBig.next;
                }
                head = head.next;
            }
            pBig.next = null;
            pSmall.next = big.next;
            return small.next;
        }
    }
}