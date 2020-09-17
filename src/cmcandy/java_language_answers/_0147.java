package cmcandy.java_language_answers;

/**
 * Created by CHEN on 2020/8/26.
 */
public class _0147 {
    //有点xiaobug

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

        ListNode(int[] list) {
            val = list[0];
            ListNode tmp = this;
            for (int i = 1; i < list.length; i++) {
                tmp.next = new ListNode(list[i]);
                tmp = tmp.next;
            }
        }

    }

    static class Solution {
        public ListNode insertionSortList(ListNode head) {
            if (head == null || head.next == null) {
                return head;
            }
            ListNode tmp = head.next;
            ListNode last = head;
            ListNode lit = head;
            while (tmp != null) {
                //待排序点先孤立起来
                last.next = tmp.next;
                ListNode snode = tmp;
                tmp = tmp.next;

                //开始排序
                if (lit.val > snode.val) {
                    //头节点比当前值小
                    snode.next = head;
                    head = snode;
                } else {
                    //开始排序
                    if (lit.next == null) {
                        //头节点比当前值小
                        snode.next = head;
                        head = snode;
                    } else {
                        while (lit.next != null) {
                            if (lit == last) {
                                snode.next = lit.next;
                                lit.next = snode;
                                last = last.next;
                                break;
                            } else if (lit.next.val >= snode.val) {
                                //如果下一个节点的数比要插入的大，则插在二者中间
                                snode.next = lit.next;
                                lit.next = snode;
                                break;
                            }
                            lit = lit.next;
                        }
                    }
                    lit = head;
                }
            }
            return head;
        }
    }

    public static void main(String[] args) {
//        int[] lis = new int[]{-1, 5, 3, 4, 0};
        int[] lis = new int[]{1, 1};
        ListNode head = new ListNode(lis);
        Solution solution = new Solution( );
        solution.insertionSortList(head);
    }
}
