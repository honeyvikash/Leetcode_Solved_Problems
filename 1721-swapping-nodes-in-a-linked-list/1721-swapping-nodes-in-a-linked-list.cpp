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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* tmp = head;
        ListNode* node1 = NULL;
        ListNode* node2 = NULL;
        int cnt = 0;
        int n = 0;
        while(tmp!=NULL)
        {
            n++;
            cnt++;
            if(cnt==k)
            {
                node1 = tmp;
            }
            tmp = tmp->next;
        }
        tmp = head;
        cnt = 0;
        while(tmp!=NULL)
        {
            cnt++;
            if(cnt==n-k+1)
            {
                node2 = tmp;
            }
            tmp = tmp->next;
        }
        swap(node1->val,node2->val);
        return head;
    }
};