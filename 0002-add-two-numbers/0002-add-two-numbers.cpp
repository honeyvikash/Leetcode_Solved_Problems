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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy;
        ListNode* head;
        head = dummy = new ListNode(-1);
        
        int carry = 0;
        
        while(l1 || l2)
        {
            int firstval = l1?l1->val:0;
            int secondval = l2?l2->val:0;
            
            int total = firstval + secondval + carry;
            carry = total/10;
            total=total%10;
            
            ListNode* newdummy = new ListNode(total);
            
            dummy->next = newdummy;
            
            dummy = dummy->next;
            
            l1=l1?l1->next:l1;
            l2=l2?l2->next:l2;
            
        }
        
        if(carry)
        {
            ListNode* newdummy = new ListNode(1);
            dummy->next = newdummy;
        }
        return head->next;
    }
};