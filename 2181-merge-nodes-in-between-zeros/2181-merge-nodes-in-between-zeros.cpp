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
    ListNode* mergeNodes(ListNode* head) {
    ListNode* temp = head;
    ListNode* naya = new ListNode(0);
    ListNode* ans = naya;
    temp=temp->next;
    int sum=0;
    while(temp )
    {
        
        if(temp->val==0)
        {
           naya->next= new ListNode(sum);
            naya=naya->next;
            sum=0;
        }
        else{
            sum+=temp->val;
        }
        temp=temp->next;
    }
    return ans->next;
  }
};