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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        

        int si = -1 , li = -1 , lv = -1 , an = 1e9 , i = 0;

        while(head->next){

            if(lv==-1){
                lv = head->val;
            }else{
                
                if((head->val > lv && head->val > head->next->val) || (head->val < lv && head->val < head->next->val)){

                    if(si==-1){
                        si = i;
                    }
                    if(li==-1){
                        li = i;
                    }else{
                        an = min(an,i-li);
                        li = i;
                    }
                }
            }
            lv = head->val;
            head=head->next;
            i++;
        }
        cout<<an<<li<<si;
       if(an==1e9)
        return {-1,-1};

        return {an,li-si};
    }
};