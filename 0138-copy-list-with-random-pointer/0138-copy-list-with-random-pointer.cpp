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
    void putDuplicateNodes(Node *head)
    {
        while( head )
        {
            head->next = new Node(head->val,head->next);
            head = head->next->next;
        }
    }
    
    void addRandomPointerToDuplicateNodes(Node *head)
    {
        while( head )
        {
            if( head->random )
                head->next->random = head->random->next;
            else
                head->next->random = NULL;
            head = head->next->next;
        }
    }
    
    Node* giveDuplicateList(Node *head)
    {
        if( NULL==head )    return head;
        Node *cp = head;
        head = head->next;
        // a A b B c C d D g G N
        // cp = c
        // nc = d
        // A B C 
        // a b c
        while( cp )
        {
            Node *nextCp = cp->next->next;
            if( nextCp && nextCp->next )
                cp->next->next = nextCp->next;
            else
                cp->next->next = NULL;
            cp->next = nextCp;
            cp = nextCp;
        }
        return head;
    }
    
    Node* copyRandomList(Node* head) {
        putDuplicateNodes(head);
        addRandomPointerToDuplicateNodes(head);
        Node *temp = head;
        // while( temp ){
        //     cout<<temp->val<<" ";
        //     if( temp->random )  cout<<temp->random->val;
        //     cout<<"\n";
        //     temp = temp->next;
        // }
        return giveDuplicateList(head);
    }
};