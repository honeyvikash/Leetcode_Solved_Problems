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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        ListNode* ans=new ListNode();
        if(list1==NULL)
        {
            return list2;
        }
        if(list2==NULL)
        {
            return list1;
        }
        if(list1->val<list2->val)
        {
            ans=list1;
            ans->next=mergeTwoLists(list1->next,list2);
        }
         else
        {
            ans=list2;
            ans->next=mergeTwoLists(list1,list2->next);
        }
        return ans;
    }
    
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next==NULL) return head;
        
        ListNode* tmp = NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast!=NULL and fast->next!=NULL)
        {
            tmp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        tmp ->next = NULL;
        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(slow);
        
        return mergeTwoLists(l1,l2);
    }
};