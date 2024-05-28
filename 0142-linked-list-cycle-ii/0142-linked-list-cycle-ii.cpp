/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // if(!head)
        // return NULL;
        // ListNode* slow = head;
        // ListNode* fast = head->next;
        // while(fast!=NULL && fast->next!=NULL && slow!=fast)
        // {
        //     slow = slow->next;
        //     fast = fast->next->next;
        // }
        // if(slow!=fast)
        // return NULL;
        // fast = head;
        // slow = slow->next;
        // while(slow!=fast)
        // {
        //     slow = slow->next;
        //     fast = fast->next;
        // }
        // return slow;
            ListNode* temp=head;
            while(temp)
            {
                if(temp->val==INT_MAX)
                {
                        return temp;
                }
                temp->val=INT_MAX;
                temp=temp->next;
            }
            return NULL;
    }
        
};