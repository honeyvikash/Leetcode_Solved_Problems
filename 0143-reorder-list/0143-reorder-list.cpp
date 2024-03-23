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
    void reorderList(ListNode* head) {
        ListNode* node=new ListNode(head->val);
        ListNode* ans=node;
        ListNode* temp=head;
        vector<int>v;
        while(temp)
        {
            v.push_back(temp->val);
            temp=temp->next;
        }
        if(v.size()<=2)return;
        int l=1,h=v.size()-1;
        while(l<=h)
        {
            ListNode* dummy1=new ListNode(v[l]);
            ListNode* dummy2=new ListNode(v[h]);

            if(l==h)
            {
                node->next=dummy2;
                node=node->next;
            }
            else 
            {
                node->next=dummy2;
                node=node->next;
                node->next=dummy1;
                node=node->next;
            }
            l++;
            h--;
        }
        // head=ans;     ------>esse assignemnt nhi hota
        *head=*ans;
    }
};