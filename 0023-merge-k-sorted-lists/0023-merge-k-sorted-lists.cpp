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


//  ---------Followed the Tutorial-------------//

class compare {
    public: 
    bool operator()(ListNode* a, ListNode* b)
    {
        return a->val>b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,compare>minHeap;
        int n= lists.size();
        if(n==0)return NULL;

        for(int i=0;i<n;i++)
        {
            if(lists[i] != NULL)
            {
                minHeap.push(lists[i]);
            }

        } 

        ListNode* head=NULL;
        ListNode* tail=NULL;
        
        while(minHeap.size()>0)
        {
            ListNode* top=minHeap.top();
            minHeap.pop();
            if(top->next != NULL)
            {
                minHeap.push(top->next);
            }
            if(head==NULL)
            {
                //ans LL is empty
                head=top;
                tail=top;
            }
            else 
            {
                //insert at LL
                tail->next=top;
                tail=top;
            }

        }
        return head;

    }
};