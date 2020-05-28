package cmcandy.Java_Language_Answers;

/**
 * Created by CHEN on 2020/4/20.
 */
public class _0021 {
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
        public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
            ListNode head, tail;
            //第一个节点
            if (l1.val > l2.val) {
                head = l2;
                l2=l2.next;
            } else {
                head = l1;
                l1=l1.next;
            }
            tail = head;
            while (l1 != null || l2 != null) {
                if (l1 == null && l2 != null) {
                    tail.next = l2;
                    l2 = l2.next;
                } else if (l1 != null && l2 == null) {
                    tail.next = l1;
                    l1 = l1.next;
                }else if (l1.val > l2.val) {
                    tail.next = l2;
                    l2 = l2.next;
                }else if (l1.val <= l2.val) {
                    tail.next = l1;
                    l1 = l1.next;
                }
                tail = tail.next;
            }
            return head;
        }
    }

    public static void main(String[] args) {
        ListNode listNode1=null;
        ListNode listNode2=null;
        ListNode temp=null;
        int[] arr1 = new int[]{1, 2, 4};
        int[] arr2 = new int[]{1, 3, 4};
        for (int i = arr1.length-1; i >=0; i--) {
            temp = new ListNode(arr1[i]);
            temp.next = listNode1;
            listNode1 = temp;
            temp = new ListNode(arr2[i]);
            temp.next = listNode2;
            listNode2 = temp;
        }
        Solution solution = new Solution();
        System.out.println(solution.mergeTwoLists(listNode1,listNode2));
    }
}
