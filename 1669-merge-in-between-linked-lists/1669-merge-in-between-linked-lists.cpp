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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* p1 = NULL;
        ListNode* p2 = NULL;
        int cnt = 0;
        ListNode* tmp = list1;
        while(tmp!=NULL && tmp->next!=NULL)
        {
            if(cnt+1==a)
            p1 = tmp;
            if(cnt==b)
            p2 = tmp;
            tmp = tmp->next;
            cnt++;
        }
        p1->next = list2;
        tmp = list2;
        while(tmp->next!=NULL)
        tmp = tmp->next;
        tmp->next = p2->next;
        p2->next = NULL;
        return list1;
    }
};