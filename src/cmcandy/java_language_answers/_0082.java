package cmcandy.java_language_answers;

import java.util.LinkedList;

public class _0082 {
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
        public ListNode deleteDuplicates(ListNode head) {
            ListNode last = new ListNode(Integer.MIN_VALUE);
            last.next = head;
            head = last;
            ListNode cur = head;
            ListNode curnext = head.next;
            LinkedList<Integer> lis = new LinkedList<>();
            lis.add(head.val);
            while(curnext!=null){
                if(curnext.val!=lis.getLast()){
                    //如果不是，那就加入
                    lis.add(curnext.val);
                    curnext = curnext.next;
                    if(curnext!=null&&curnext.val != lis.getLast()){
                        cur = cur.next;
                    }
                }
                else if(curnext.val==lis.getLast()){
                    cur.next = curnext.next;
                    curnext = cur.next;
                }
            }
            return head.next;
        }
    }
    public static void main(String[] args) {

        ListNode head = new ListNode(1);
        ListNode cur = head;
        cur.next = new ListNode(1);
        cur = cur.next;
        cur.next = new ListNode(1);
        cur = cur.next;
        cur.next = new ListNode(1);
        cur = cur.next;
        cur.next = new ListNode(2);
        cur = cur.next;
        cur.next = new ListNode(3);
        cur = cur.next;
      
        
        Solution solution = new Solution();
        head = solution.deleteDuplicates(head);
        while(head!=null){
            System.out.println(head.val);
            head = head.next;
        }
    }
}