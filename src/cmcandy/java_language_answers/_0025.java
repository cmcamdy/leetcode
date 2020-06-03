package cmcandy.java_language_answers;

/**
 * Created by CHEN on 2020/4/22.
 */
public class _0025 {

    static class ListNode {
        int val;
        ListNode next;

        ListNode(int x) {
            val = x;
        }
    }

    static class Solution {

        public ListNode reverseKGroup(ListNode head, int k) {
            if (head == null) return head;
            ListNode cur = head;
            int i = k;
            //先做下一段，所以先找下一段的头部
            while (i > 0 && cur != null) {
                cur = cur.next;
                i--;
            }
            //长度达不到要求的，不用换
            if (i > 0) return head;
            //递归进行下一轮
            ListNode pre = reverseKGroup(cur, k);
            i = k;
            cur = head;
            ListNode tmp  = null;
            //k个转换
            while (i>0){
                tmp = cur.next;
                cur.next = pre;
                pre = cur;
                cur = tmp;
                i--;
            }
            return pre;
        }


    }

    public static void main(String[] args) {
        int[] arr1 = new int[]{1, 2, 3, 4, 5};
        ListNode listNode1 = null;
        ListNode temp = null;
        for (int i = arr1.length - 1; i >= 0; i--) {
            temp = new ListNode(arr1[i]);
            temp.next = listNode1;
            listNode1 = temp;
        }
        Solution solution = new Solution( );
        listNode1= solution.reverseKGroup(listNode1, 3);
        System.out.println(listNode1);
    }
}
