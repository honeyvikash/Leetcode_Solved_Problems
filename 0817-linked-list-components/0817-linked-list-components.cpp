/*
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
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int>st ;
        for(auto it : nums) st.insert(it) ;

        ListNode* temp = head ;
        int cnt = 0 ; 
        int streak = 0 ;

        while(temp!=NULL)
        {
            int v = temp->val ;
            if(st.find(v)!=st.end())
            {
                if(streak==0) cnt++ ;
                
                streak++ ;
            }
            else streak = 0;
            temp = temp->next ;
        }
        return cnt ;
    }
};