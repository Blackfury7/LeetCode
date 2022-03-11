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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
            dummy->next = head;
        ListNode* temp1 = head;
        ListNode* temp2 = head;
        ListNode* prev ;
        
        if(!k || !head || !head->next)return head;
        int f=1;
        while(temp2 && temp2->next) {
            f++;
            temp2 = temp2->next;
            
        }
        
        k %= f;
        if(!k)return head;
       
        k = f - k;
        
         cout<<f<<" "<<k;
        int i=0;
        
        
        while(temp1 && temp1->next){
            
            if(i==k)
                break;
            prev=temp1;
            temp1=temp1->next;
            i++;
        }
        prev->next=NULL;
        dummy->next=temp1;
        temp2->next = head;
        
        return dummy->next;
        
        
        
    }
};