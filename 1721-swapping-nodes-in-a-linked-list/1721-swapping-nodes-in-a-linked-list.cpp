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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* slow  = head;
        ListNode* fast  = head;
        ListNode* l1  = head;
        for(int i=0;i<k-1;i++)
        {
            fast = fast->next;
            l1 = fast;
        }
        while(fast->next)
        {
            fast = fast->next;
            slow = slow->next;
        }
        swap(slow->val,l1->val);
        return head;
    }
};