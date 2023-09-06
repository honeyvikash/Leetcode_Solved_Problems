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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans;
        int n = 0;
        ListNode* tmp = head;
        while(tmp!=NULL)
        {
            n++;
            tmp = tmp->next;
        }
        if(n<=k)
        {
            tmp = head;
            while(tmp!=NULL)
            {
                ListNode* node = tmp;
                tmp = tmp->next;
                node->next = NULL;
                ans.push_back(node);
            }
            int cnt = k-n;
            while(cnt)
            {
                cnt--;
                ans.push_back(NULL);
            }
            return ans;
        }
        int rem = n%k;
        int len = n/k;
        tmp = head;
        while(tmp!=NULL)
        {
            ListNode* node = tmp;
            int tmpl = 0;
            if(rem>0)
            {
                tmpl = len+1;
                rem--;
            }
            else
            tmpl = len;
            ans.push_back(node);
            tmpl--;
            if(tmpl!=0)
            tmp = tmp->next;
            while(tmpl && tmp!=NULL)
            {
                tmpl--;
                if(tmpl!=0)
                tmp = tmp->next;
            }
            if(tmp!=NULL)
            {
                ListNode* tmp1 = tmp->next;
                tmp->next = NULL;
                tmp = tmp1;
            }
        }
        return ans;
    }
};