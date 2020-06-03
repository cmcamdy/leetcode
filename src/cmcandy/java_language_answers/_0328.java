public class _0328 {
    /**
     * Definition for singly-linked list. public class ListNode { int val; ListNode
     * next; ListNode() {} ListNode(int val) { this.val = val; } ListNode(int val,
     * ListNode next) { this.val = val; this.next = next; } }
     */

    static public class ListNode {
        int val;
        ListNode next;

        ListNode() {
        }

        ListNode(int val) {
            this.val = val;
        }

        ListNode(int val, ListNode next) {
            this.val = val;
            this.next = next;
        }
    }

    static class Solution {
        public ListNode oddEvenList(ListNode head) {

            int tag = 0;
            ListNode oddLis = new ListNode();
            ListNode evenLis = new ListNode();
            ListNode curOdd = oddLis;
            ListNode curEven = evenLis;

            ListNode cur = head;

            while (cur != null) {
                if (tag == 0) {
                    curOdd.next = cur;
                    curOdd = curOdd.next;
                    tag = 1;
                } else if (tag == 1) {
                    curEven.next = cur;
                    curEven = curEven.next;
                    tag = 0;
                }
                cur = cur.next;
            }
            curEven.next = null;
            curOdd.next = evenLis.next;
            return oddLis.next;

        }
    }
    public static void main(String[] args) {
        Solution solution = new Solution();
        ListNode head2 = new ListNode(1);
        ListNode head = head2;
        ListNode cur = new ListNode(2);
        head.next = cur;
        head = head.next;
        cur = new ListNode(3);
        head.next = cur;
        head = head.next;
        cur = new ListNode(4);
        head.next = cur;
        head = head.next;
        cur = new ListNode(5);
        head.next = cur;
        head = head.next;
        System.out.println(solution.oddEvenList(head2));
    }
}