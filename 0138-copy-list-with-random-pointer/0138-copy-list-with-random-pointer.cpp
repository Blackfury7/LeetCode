/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL)
        {
            return NULL;
        }
        map<Node*,Node*>mp;
        Node*temp=head;
        Node*head2=new Node(-1);
        Node*temp2=new Node(-1);
        while(temp!=NULL)
        {
            Node* x=new Node(temp->val);
            mp[temp]=x;
            if(temp==head)
            {
                head2=x;
                temp2=x;
            }
            else
            {
                temp2->next=x;
                temp2=x;
            }
            temp=temp->next;
        }
        temp=head;
        temp2=head2;
        while(temp!=NULL)
        {
            if(temp->random!=NULL)
            {
                temp2->random=mp[temp->random];
            }
            temp=temp->next;
            temp2=temp2->next;
        }
        return head2;
    }
};