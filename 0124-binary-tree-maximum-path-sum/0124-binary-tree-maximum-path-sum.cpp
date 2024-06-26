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
    int sol(TreeNode* root,int &ans)
    {
        if(root==NULL)return 0;
        
        int l = max(sol(root->left,ans),0);
        int r = max(sol(root->right,ans),0);
        ans = max(ans, root->val+(l+r));
        return root->val+ max(l,r);
    }
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        sol(root,ans);
        return ans;
    }
};