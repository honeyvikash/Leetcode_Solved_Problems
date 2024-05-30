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
        map<Node *,Node *>mp;
        Node * temp=head;
        while(temp!=NULL)
        {
            Node * dalo=new Node(temp->val);
            mp[temp]=dalo;
            temp=temp->next;
        }
        temp=head;
        Node* ans=mp[temp];
        while(temp!=NULL)
        {
            Node* aage=mp[temp];
            aage->next=mp[temp->next];
            aage->random=mp[temp->random];
            temp=temp->next;
        }
        return ans;
    }
};