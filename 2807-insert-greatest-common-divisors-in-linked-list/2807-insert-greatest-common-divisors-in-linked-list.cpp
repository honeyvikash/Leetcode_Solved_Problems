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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head==NULL || head->next==NULL)return head;
        ListNode* prev=head;
        ListNode* curr=head->next;
        while(curr)
        {
            int a = prev->val;
            int b = curr->val;
            ListNode* newnode = new ListNode(__gcd(a,b));
            prev->next = newnode;
            newnode->next = curr;
            prev = curr;
            curr = curr->next;
        }
        return head;
    }
};