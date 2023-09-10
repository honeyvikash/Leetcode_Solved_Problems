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
    TreeNode* solve(TreeNode* root,int val)
    {
        if(!root)
            return new TreeNode(val);
        if(root->val>val)
        {
            if(root->left)
                solve(root->left,val);
            else
                root->left = new TreeNode(val);
        }
        if(root->val<val)
        {
            if(root->right)
                solve(root->right,val);
            else
                root->right = new TreeNode(val);
        }
        return root;
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        return solve(root,val);
    }
};