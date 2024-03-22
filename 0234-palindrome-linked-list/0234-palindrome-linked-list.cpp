class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head -> next == NULL)
            return true;
        ListNode * slow = head; 
        ListNode * fast = head; 
        while(fast && fast->next)
        {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        ListNode *prev, *curr, *nextNode;
        prev = NULL;
        curr = slow;
        while(curr)
        {
            nextNode = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = nextNode;
        }
        while(prev){
            if(prev -> val != head -> val)
                return false;
            prev = prev -> next;
            head = head -> next;
        }
        return true;
    }
};