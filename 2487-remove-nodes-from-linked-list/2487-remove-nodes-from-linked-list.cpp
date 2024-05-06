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
    ListNode* removeNodes(ListNode* head) {
        vector< int > temp;
        ListNode *pt = head;
        while( pt )
        {
            temp.push_back(pt->val);
            pt = pt->next;
        }
        int len=temp.size();
        
        for(int i=len-2 ; i>=0 ; i--)
        {
            temp[i] = max(temp[i],temp[i+1]);
        }
        ListNode *newHead = new ListNode();
        newHead->next = head;
        pt = newHead;
        
        for(int i=0 ; i<temp.size() ; i++)
        {
            if( temp[i]>pt->next->val )
            {
                pt->next = pt->next->next;
            }
            else
                pt = pt->next;
        }
        return newHead->next;
    }
};