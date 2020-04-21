package cmcandy.solutions;

/**
 * Created by CHEN on 2020/4/21.
 */
public class _0023 {

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
        public ListNode mergeKLists(ListNode[] lists) {
            if(lists.length == 0)
                return null;
            if(lists.length == 1)
                return lists[0];
            if(lists.length == 2){
                return mergeTwoLists(lists[0],lists[1]);
            }
            int mid = lists.length/2;
            ListNode[] l1 = new ListNode[mid];
            ListNode[] l2 = new ListNode[lists.length- mid];
            for (int i = 0 ;i<mid;i++){
                l1[i] = lists[i];
            }
            for(int i = mid;i<lists.length;i++){
                l2[i-mid] = lists[i];
            }
            return mergeTwoLists(mergeKLists(l1),mergeKLists(l2));
        }

        public ListNode mergeTwoLists(ListNode l1,ListNode l2) {
            if (l1==null){
                return l2;
            }else if (l2==null){
                return l1;
            }
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



}
