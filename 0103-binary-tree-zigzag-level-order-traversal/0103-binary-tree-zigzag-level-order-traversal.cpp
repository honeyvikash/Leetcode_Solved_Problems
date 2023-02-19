/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector< vector<int> >ans;
        ans.push_back(vector<int>());
        
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        
        while( NULL!=q.front() )
        {
            ans.back().push_back(q.front()->val);
            TreeNode *temp = q.front();
            q.pop();
            if( NULL!=temp->left )
                q.push(temp->left);
            if( NULL!=temp->right )
                q.push(temp->right);
            if( NULL==q.front() )
            {
                ans.push_back(vector<int>());
                q.pop();
                q.push(NULL);
            }
        }
        ans.pop_back();
        bool sign = false;
        for(auto &val : ans){
            if( sign )
                reverse(val.begin(),val.end());
            sign ^= 1;
        }
        return ans;
    }
};