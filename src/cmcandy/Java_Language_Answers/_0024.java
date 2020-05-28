package cmcandy.Java_Language_Answers;

/**
 * Created by CHEN on 2020/4/21.
 */
public class _0024 {
    /**
     * Definition for singly-linked list.
     * public class ListNode {
     *     int val;
     *     ListNode next;
     *     ListNode(int x) { val = x; }
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
        public ListNode swapPairs(ListNode head) {
            if (head==null||head.next==null) return head;
            ListNode temp = new ListNode(1);
            ListNode tail = head;
            head = head.next;
            temp.next = tail.next.next;
            head.next = tail;
            tail.next = temp.next;
            while(tail!=null&&tail.next!=null&&tail.next.next!=null){
                temp.next = tail.next.next.next;
                tail.next.next.next = tail.next;
                tail.next = tail.next.next;
                tail.next.next.next = temp.next;
                tail = tail.next.next;
            }
            return head;
        }
    }

    public static void main(String[] args) {
        int[] arr1 = new int[]{1,2, 3, 4};
        ListNode listNode1=null;
        ListNode temp=null;
        for (int i = arr1.length-1; i >=0; i--) {
            temp = new ListNode(arr1[i]);
            temp.next = listNode1;
            listNode1 = temp;
        }
        Solution solution  = new Solution();
        System.out.println(solution.swapPairs(listNode1) );

    }
}
