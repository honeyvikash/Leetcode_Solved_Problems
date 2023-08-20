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
    long long ans = 0;
    void sumofNodes(TreeNode* root,long long targetSum)
    {
        if(root==NULL)return;
        targetSum-=root->val;
        if(targetSum==0)ans++;
        sumofNodes(root->left,targetSum);
        sumofNodes(root->right,targetSum);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL)return 0;
        sumofNodes(root,targetSum);
        pathSum(root->left,targetSum);
        pathSum(root->right,targetSum);
        return ans;
    }
};