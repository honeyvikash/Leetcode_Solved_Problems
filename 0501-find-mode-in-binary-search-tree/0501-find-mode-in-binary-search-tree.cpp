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
void solve(TreeNode* root,unordered_map<int, int> &m)
{
    if(root==NULL)return ;
    
    m[root->val]++;
    solve(root->left,m);
    solve(root->right,m);
}
    vector<int> findMode(TreeNode* root) {
        if(root==NULL)return {};
        vector<int> ans;
        unordered_map<int, int> m;
        solve(root, m);
        int maxi = 0;
        for(auto &x: m) 
        {
            if(x.second > maxi) 
            {
                maxi = x.second;
            }
        }
        for(auto &x: m) 
        {
            if(x.second == maxi) {
                ans.push_back(x.first);
            }
        }
        return ans;
    }
};