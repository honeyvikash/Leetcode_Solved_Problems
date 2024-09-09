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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m,vector<int>(n,-1));

        int toprow=0,botrow=m-1,lftcol=0,rgtcol=n-1;

        while(head!=NULL){
            for(int col = lftcol;col <= rgtcol && head; col++){
                ans[toprow][col] = head->val;
                head=head->next;
            }
            toprow++;
            for(int row=toprow;row<=botrow && head; row++){
                ans[row][rgtcol] = head->val;
                head=head->next;
            }
            rgtcol--;
            for(int col=rgtcol;col>=lftcol && head; col--){
                ans[botrow][col] = head->val;
                head=head->next;
            }
            botrow--;
            for(int row=botrow;row>=toprow && head; row--){
                ans[row][lftcol] = head->val;
                head=head->next;
            }
            lftcol++;
        }
        return ans;
    }
};