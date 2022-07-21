/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int position) {
        ListNode temp1 = head; int n=0;
        while(temp1!=null){
            n++;
            temp1 = temp1.next;
        }
        int i=1; 
        // if position is head
        if(n-position == 0){
            head=head.next;
            return head;
        }
        temp1=head;
        while(i<n-position){
                i++;
                temp1=temp1.next;   
            }
        temp1.next = temp1.next.next;
        return head;
    }
}
