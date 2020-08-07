package cmcandy.java_language_answers;


/**
 * Created by CHEN on 2020/8/7.
 */
public class _0092 {
    /**
     * Definition for singly-linked list.
     * public class ListNode {
     * int val;
     * ListNode next;
     * ListNode(int x) { val = x; }
     * }
     */
    static public class ListNode {
        int val;
        ListNode next;

        ListNode(int x) {
            val = x;
        }

        ListNode(int[] list) {
            val = list[0];
            ListNode tmp = this;
            for (int i = 1; i < list.length; i++) {
                ListNode next = new ListNode(list[i]);
                tmp.next = next;
                tmp = tmp.next;
            }
        }

        @Override
        public String toString() {
            return val + "-->" + next;
        }
    }

    static class Solution {
        public ListNode reverseBetween(ListNode head, int m, int n) {
            if (m == n) return head;

            //记录m、n两处断点
            ListNode tmp1, tmp2;
            ListNode p = head;
            ListNode p_last, p_next;
            for (int i = 1; i < m - 1; i++) {
                p = p.next;
            }
            if (m > 1) {
                //此时已经到了m的前一个，记录，最后需要用到
                tmp1 = p;
                tmp2 = p.next;
                p = p.next;
            } else {
                tmp1 = null;
                tmp2 = p;
            }

            //翻转三人组的初始化
            p_last = p;
            p = p.next;
            p_next = p.next;

            //这里开始翻转
            for (int i = m; i < n; i++) {
                p.next = p_last;
                p_last = p;
                p = p_next;
                //万一走到最后一个了，立刻停，反正下面的也不用翻转
                if (p_next != null)
                    p_next = p_next.next;
            }

            if (tmp1 != null) {
                tmp1.next = p_last;
            } else {
                head = p_last;
            }
            tmp2.next = p;

            return head;
        }
    }

    public static void main(String[] args) {
        ListNode lis = new ListNode(new int[]{1, 2});
        System.out.println(lis);
        Solution solution = new Solution( );
        System.out.println(solution.reverseBetween(lis, 1, 2));
    }
}
