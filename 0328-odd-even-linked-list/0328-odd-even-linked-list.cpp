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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode* oddhead = NULL;
        ListNode* evenhead = NULL;
        ListNode* oddtail = NULL;
        ListNode* eventail = NULL;
        
        int cnt = 1;
        while(head!=NULL)
        {
            if(cnt%2!=0)
            {
                if(oddtail==NULL)
                {
                    oddhead = head;
                    oddtail = head;
                    head = head->next;
                }
                else
                {
                    oddtail->next = head;
                    oddtail = oddtail->next;
                    head = head->next;
                }
            }
            else
            {
               if(eventail==NULL)
                {
                    evenhead = head;
                    eventail = head;
                    head = head->next;
                }
                else
                {
                    eventail->next = head;
                    eventail = eventail->next;
                    head = head->next;
                } 
            }
            cnt++;
        }
        eventail->next = NULL;
        oddtail->next = evenhead;
        
        return oddhead;
    }
};