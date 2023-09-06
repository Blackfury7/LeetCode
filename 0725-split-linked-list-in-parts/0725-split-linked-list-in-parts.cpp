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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        if(head==NULL)
            return vector<ListNode*>(k,NULL);
        vector<ListNode*> ans;
        ListNode* temp=head;
        int cnt=0;
       
        while(temp!=NULL)
        {
            cnt++;
            temp=temp->next;
        }
        int extracount=cnt%k; 
        int size=cnt/k;
        ListNode* curr=head;
        ListNode* newHead=head;

        int c=1;
        while(curr!=NULL)
        {
            if(c==size+(extracount>0))
            {
                ListNode* temp=curr->next;
                curr->next=NULL;
                ans.push_back(newHead);
                newHead=temp;
                curr=temp;
                c=1;
                if(extracount)extracount--;
                continue;

            }
            c++;
            curr=curr->next;
        }
        while(ans.size()<k)
        {
            ans.push_back(NULL);
        }
        return ans;

    }
};