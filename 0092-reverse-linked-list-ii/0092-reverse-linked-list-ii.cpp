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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* tmp = new ListNode(0); //safeplayer hehe :)
        tmp -> next = head;
        ListNode* lprev = tmp;
        ListNode* curr = head;

        for(int i=1;i<left;i++)
        {
            lprev = curr;
            curr = curr->next;
        }
        ListNode* prev = NULL;
        for(int i=0;i<right-left+1;i++)
        {
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        } 
        
        lprev->next->next = curr;
        lprev->next = prev;

        return tmp->next;
    }
};