public class _0725 {
    /**
     * Definition for singly-linked list. public class ListNode { int val; ListNode
     * next; ListNode(int x) { val = x; } }
     */
    static public class ListNode {
        int val;
        ListNode next;

        ListNode(int x) {
            val = x;
        }
    }

    static class Solution {
        public ListNode[] splitListToParts(ListNode root, int k) {
            int index = 0;
            ListNode cur = root;
            while (cur != null) {
                index++;
                cur = cur.next;
            }
            int len = index / k;
            int remain = index % k;
            ListNode[] lists = new ListNode[k];
            cur = root;
            int tmp = 1;
            int i = 0;
            lists[0] = root;
            ListNode tmpNode;
            while (cur != null) {
                if (tmp == (len + (remain - 1 >= i ? 1 : 0))) {
                    tmpNode = cur;
                    cur = cur.next;
                    tmpNode.next = null;
                    tmp = 1;
                    i++;
                    if (i<k)    lists[i] = cur;
                } else {
                    tmp++;
                    cur = cur.next;
                }
            }
            return lists;
        }
    }
    public static void main(String[] args) {
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
        cur = new ListNode(6);
        head.next = cur;
        head = head.next;
        cur = new ListNode(7);
        head.next = cur;
        head = head.next;

        Solution solution = new Solution();
        solution.splitListToParts(head2,3);
    }
}