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
    bool isvalid(TreeNode* root,long minVal,long maxVal)
    {
        if(root==NULL )return true;
        if(root->val>=maxVal || root->val<=minVal)return false;
        return (isvalid(root->left,minVal,root->val) && isvalid(root->right,root->val,maxVal));
    }
    bool isValidBST(TreeNode* root) {
        long mini=LONG_MIN;
        long maxi=LONG_MAX;
        return isvalid(root,mini,maxi);
    }
};