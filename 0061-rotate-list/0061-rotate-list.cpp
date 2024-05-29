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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head -> next == NULL || k == 0)
        {
            return head;
        }
        
        int n = 1;
        ListNode* tmp = head;
        
        while(tmp->next != NULL)
        {
            n++;
            tmp = tmp -> next;
        }        
        
        k = k % n;

        if(k == 0)
        {
            return head;
        }

        ListNode* curr = head;
        int p= n-k-1;
        while(p>0)
        {
            curr = curr -> next;
            p--;
        }
        tmp -> next = head;
        head = curr->next;
        curr->next = NULL;

        return head;
    }
};