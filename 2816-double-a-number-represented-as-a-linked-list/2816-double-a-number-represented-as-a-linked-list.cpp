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
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(curr)
        {
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        head = prev;
        return head;
    }
    
        

    int carry = 0;
    ListNode* Doublekra(ListNode* head)
    {
        ListNode* dummy = new ListNode(-1);
        ListNode* newHead = dummy;
        int carry = 0;
        while(head or carry)
        {
            int temp = 0;
            if(head)
            {
                temp = head->val + head->val;
            }
            temp += carry;
            
            ListNode* node = new ListNode(temp%10);
            carry = temp/10;
            
            dummy->next = node;
            dummy = dummy->next;
            
            if(head)head = head->next;
        }
        
        return newHead->next;
    }
    
    ListNode* doubleIt(ListNode* head) {
        // similar to add two numbers
        ListNode* l1 = head;
        l1 = reverseList(l1);
        return reverseList(Doublekra(l1));
    }
};