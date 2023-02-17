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
    vector<int>v;
    int minDiffInBST(TreeNode* root) {
        trav(root);
        int n=v.size();
        int ans=INT_MAX;

        for(int i=1;i<n;i++)
        {
            ans=min(ans,v[i]-v[i-1]);
        }
        return ans;
    }
    void trav(TreeNode* root)
    {
        if(root==NULL)return;
        trav(root->left);
        v.push_back(root->val);
        trav(root->right);
    }
};