class Solution {
public:
    Node* flatten(Node* head) {
        Node *temp = head;
        while(temp)
        {
            if(temp -> child)
            {
                Node *chld = temp -> child , *i = temp -> next;
                temp -> next = chld;
                chld -> prev = temp;
                while(chld -> next)
                chld = chld -> next;
                chld -> next = i;
                if(i)
                i -> prev = chld;
            }
            temp -> child = NULL;
            temp = temp -> next;
        }
        return head;
    }
};