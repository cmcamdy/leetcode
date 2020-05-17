package cmcandy.solutions;

/**
 * Created by CHEN on 2020/5/18.
 */
public class _0061 {
    static
    /**
     * Definition for singly-linked list.
     * public class ListNode {
     *     int val;
     *     ListNode next;
     *     ListNode(int x) { val = x; }
     * }
     */
    // Definition for singly-linked list.
    public class ListNode {
        int val;
        ListNode next;

        ListNode(int x) {
            val = x;
        }
    }

    class Solution {
        public ListNode rotateRight(ListNode head, int k) {
            if (head == null) return null;
            ListNode tmp = head;
            ListNode nhead = head;
            int num = 1;
            while (tmp.next != null) {
                tmp = tmp.next;
                num++;
            }
            tmp.next = head;
            while (k >= num) {
                k -= num;
            }
            for (int i = num - k; i > 1; i--) {
                head = head.next;
            }
            nhead = head.next;
            head.next = null;
            return nhead;
        }
    }
}
