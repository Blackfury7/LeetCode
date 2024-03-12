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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        int prefix = 0;
        unordered_map<int, ListNode*> seen;
        for (ListNode* i = dummy; i; i = i->next) {
            seen[prefix += i->val] = i;
        }
        prefix = 0;
        for (ListNode* i = dummy; i; i = i->next) {
            i->next = seen[prefix += i->val]->next;
        }
        return dummy->next;
    }
};