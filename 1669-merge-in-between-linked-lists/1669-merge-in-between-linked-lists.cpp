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
    ListNode* mergeInBetween(ListNode* A, int a, int b, ListNode* B) {
        ListNode *q = A, *p = NULL;
        for (int i = 0; i < b; ++i) {
            if (i == a - 1) p = q;
            q = q->next;
        }
        p->next = B;
        while (B->next) B = B->next;
        B->next = q->next;
        return A;
    }
};