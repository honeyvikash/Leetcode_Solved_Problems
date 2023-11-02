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
    pair<int,int> solve(TreeNode* root)
    {
        if(root==NULL)
        {
            return {0,0};
        }
        pair<int,int>l= solve(root->left);
        pair<int,int>r= solve(root->right);

        int sum= l.first+ r.first+ root->val;
        int n= l.second+ r.second+ 1;

        if((sum/n)==root->val) ans++;
        return {sum,n};
    }
    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return ans;
    }
};