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
    int pairSum(ListNode* head) {
        // applying  using stack
        stack<int>st;
         ListNode* temp=head;
         int cnt=0;
        while(temp)
        {
            st.push(temp->val);
            cnt++;
            temp=temp->next;
        }
        int ans=INT_MIN;
        ListNode* temp1=head;
        while(cnt--)
        {
            ans=max(ans,(st.top()+temp1->val));
            st.pop();
            temp1=temp1->next;
        }
        return ans;
    }
};