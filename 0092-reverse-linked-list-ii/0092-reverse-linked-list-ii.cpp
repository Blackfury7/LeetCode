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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        vector<int>v;
        ListNode *temp;
        temp = head;
        while(temp){
            v.push_back(temp->val);
            temp = temp->next;
        }
        int n = v.size();
        temp = head;
        for(int i=0,j = right -1; i<n;i++){
            if(i>=left-1 && i<right){
                temp->val = v[j];
                j--;
            }
            temp=temp->next;
        }
        return head;
    }
};