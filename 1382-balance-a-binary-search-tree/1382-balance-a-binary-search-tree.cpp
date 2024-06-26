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
    TreeNode* create(vector<int>&v,int s,int e)
    {
        if(s>e)return NULL;
        int mid=s+(e-s)/2;
        TreeNode* root=new TreeNode(v[mid]);
        root->left=create(v,s,mid-1);
        root->right=create(v,mid+1,e);
        return root;
    }
    void pre(TreeNode* root,vector<int>&v)
    {
        if(root==NULL)return;
        pre(root->left,v);
        v.push_back(root->val);
        pre(root->right,v);
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>v;
        pre(root,v);
        int s = 0, e = v.size()-1;;
        return create(v,s,e);
    }
};