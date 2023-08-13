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
    bool ans;
    int solve(TreeNode* root)
    {
        if(!root)
            return 0;
        if(root->left==NULL && root->right==NULL)
            return 1;
        int l = solve(root->left);
        int r = solve(root->right);
        if(abs(l-r)>1)
        {
            ans = false;
        }
        return max(l,r)+1;
    }
    bool isBalanced(TreeNode* root) {
        ans = true;
        solve(root);
        return ans;
    }
};