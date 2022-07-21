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
// class Solution {
//     public ListNode removeNthFromEnd(ListNode head, int n) {
        
//     }
// }


class Solution {
    public ListNode removeNthFromEnd(ListNode head, int position) {
        ListNode curr = head; int n=0;
        while(curr!=null)
        {
            n++;
            curr = curr.next;
        }
        if(n<2)return null;
        
           if (head == null)
            return head;
       
        ListNode temp = head;
 
      if (position == 0)
        {
            head = temp.next;   
            return head;
        }
 
        int i=1; ListNode temp1=head;
        
        // if position is head
        if(n-position == 0){
            head=head.next;
            return head;
        }
        
        
    while(i<n-position){i++;
            temp1=temp1.next;
            
            }
        // if position is end node
        if(position == 0)
        {
            temp1.next=null;
            return head;
        }
        
       // System.out.println(temp1.val);
        
        // if position is in middle
        temp1.next = temp1.next.next;
           
        // if (temp == null || temp.next == null)
        //     return null;
//         ListNode next = temp.next.next;
 
//         temp.next = next.next;
        return head;
    }
}
