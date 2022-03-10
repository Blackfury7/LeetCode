/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    ListNode* reverse(ListNode* l1){
        ListNode* l2;
        // while(true){return l2;}
        return{};
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // ListNode* l3 = (ListNode)(malloc(sizeof(ListNode) * sizeof(l1)));
        ListNode l(0) ;
        ListNode* l3 = &l;
        
        int rem=0;
        while(l1 || l2 || rem){
            int sum = (l1?l1->val:0) + (l2?l2->val:0) + rem;
            l3->next=new ListNode(sum%10);
            rem = (sum)/10;
            l1=l1?l1->next:l1;
            l2=l2?l2->next:l2;
            l3 = l3->next;
        }
        
        // reverse(head);
        return l.next;
        
    }
};