package cmcandy.solutions;

/**
 * Created by CHEN on 2020/4/4.
 */
public class _0002 {
    /**
     给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

     如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

     您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

     示例：

     输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
     输出：7 -> 0 -> 8
     原因：342 + 465 = 807

     */

    /**
     * Definition for singly-linked list.
     **/
    public class ListNode {
        int val;
        ListNode next;

        ListNode(int x) {
            val = x;
        }
    }

    class Solution {
        public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
            ListNode answer = l1;
            int add = 0;
            //如果l1.next ==null则，l1
            while (l2 != null && l1 != null) {
                l1.val += l2.val;

                if (add == 1) {
                    l1.val += 1;
                    add = 0;
                }
                if (l1.val >= 10) {
                    l1.val -= 10;
                    add = 1;
                }
                if (l1.next == null && add == 1) {
                    l1.next = new ListNode(1);
                    add = 0;
                } else if (l1.next == null && l2.next != null) {
                    l1.next = new ListNode(0);
                } else if (l2.next == null && add == 1) {
                    l2.next = new ListNode(0);
                }
                l1 = l1.next;
                l2 = l2.next;
            }
            return answer;
        }
    }


}
