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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int,int> m;
        for(auto x : nums) m[x]++;
        while(m.find(head->val)!=m.end())
        {
            head = head->next;
        }

        ListNode* prev = head;
        ListNode* ans = head;
        while(head){
            if(m.find(head->val)!=m.end())
            {
                head = head->next;
                prev -> next = head;
            } 
            else 
            {
                prev = head;
                head = head->next;
            }
        }
        return ans;
    }
};