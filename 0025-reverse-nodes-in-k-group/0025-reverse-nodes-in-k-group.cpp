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
    int len(ListNode* head)
    {
        int count = 0;
        while(head!=NULL)
        {
            count++;
            head = head->next;
        }
        return count;
    }
    ListNode* solve(ListNode* head,int k,int len)
    {
        if(head == NULL) return NULL;
        if(len<k)  return head;
        int count = k;
        ListNode* p = NULL;
        ListNode* q = head;
        ListNode* r = NULL;
        while(count > 0)
        {
            r = q->next;
            q->next = p;
            p = q;
            q = r;
            count--;
        }
        head->next = solve(q,k,len-k);
        return p;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int size = len(head);
        return solve(head,k,size);
    }
};
