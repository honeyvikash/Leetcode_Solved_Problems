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
    int ans = 0;
    void summ(TreeNode* root, int low, int high)
    {
        if(root==NULL)return;
        if(root->val>=low && root->val<=high)
        {
            ans+=root->val;
            summ(root->left,low,high);
            summ(root->right,low,high);
        }
        else if(root->val>high)
        {
            summ(root->left,low,high);
        }
        else
        {
            summ(root->right,low,high);
        }
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        ans=0;
        summ(root,low,high);
        return ans;
    }
};