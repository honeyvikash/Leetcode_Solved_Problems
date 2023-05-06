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
    int ans=0;
    void summ(TreeNode* root, long long tar)
    {
        if(root==NULL)return ;
        tar -=root->val;
        if(tar==0)ans++;
        summ(root->left,tar);
        summ(root->right,tar);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL)return 0;
        summ(root,targetSum);
        pathSum(root->left,targetSum);
        pathSum(root->right,targetSum);
        return ans;
    }
};