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
        ListNode* tmp1 = l1;
        ListNode* tmp2 = l2;
        ListNode* prev = NULL;
        
        while(tmp1->next!=NULL)
        {
            ListNode* tmp = tmp1->next;
            tmp1->next = prev;
            prev = tmp1;
            tmp1 = tmp;
        }
        
        tmp1->next = prev;
        prev = NULL;
        
        while(tmp2->next!=NULL)
        {
            ListNode* tmp = tmp2->next;
            tmp2->next = prev;
            prev = tmp2;
            tmp2 = tmp;
        }
        
        tmp2->next = prev;
        int carry = 0;
        ListNode* head = new ListNode();
        ListNode* tmpHead = head;
        
        while(tmp1!=NULL && tmp2!=NULL)
        {
            ListNode* node = new ListNode();
            int sum = tmp1->val+tmp2->val+carry;
            node->val = sum%10;
            carry = sum/10;
            tmp1 = tmp1->next;
            tmp2 = tmp2->next;
            head->next = node;
            head = head->next;
        }
        
        while(tmp1!=NULL)
        {
            ListNode* node = new ListNode();
            int sum = tmp1->val+carry;
            node->val = sum%10;
            carry = sum/10;
            tmp1 = tmp1->next;
            head->next = node;
            head = head->next;
        }
        
        while(tmp2!=NULL)
        {
            ListNode* node = new ListNode();
            int sum = tmp2->val+carry;
            node->val = sum%10;
            carry = sum/10;
            tmp2 = tmp2->next;
            head->next = node;
            head = head->next;
        }
        
        if(carry)
        {
            ListNode* node = new ListNode(carry);
            head->next = node;
            head = node;
        }
        
        head = tmpHead->next;
        ListNode* tmp = head;
        prev = NULL;
        
        while(tmp->next!=NULL)
        {
            ListNode* node = tmp->next;
            tmp->next = prev;
            prev = tmp;
            tmp = node;
        }
        
        tmp->next = prev;
        return tmp;
    }
};