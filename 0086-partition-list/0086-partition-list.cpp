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
    ListNode* partition(ListNode* head, int x) {
        ListNode* left = new ListNode(0);
        ListNode* right = new ListNode(0);
        ListNode* tmp = head;
        ListNode* l = left;
        ListNode* r = right;
        while(tmp!=NULL)
        {
            if(tmp->val<x)
            {
                l->next= tmp;
                if(l->next!=NULL)
                l = l->next;
            }
            else
            {
                r->next = tmp;
                if(r!=NULL)
                r = r->next;
            }
            tmp = tmp->next;
        }
        r->next = NULL;
        l->next = right->next;
        return left->next;
    }
};