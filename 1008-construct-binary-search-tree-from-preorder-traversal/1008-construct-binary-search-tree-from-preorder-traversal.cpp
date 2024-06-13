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
    TreeNode* pre(vector<int>& preorder,int mini,int maxi,int &i)
    {
        if(i>=preorder.size() || preorder[i]<mini || preorder[i]>maxi)return NULL;

        TreeNode* root=new TreeNode(preorder[i++]);
        root->left=pre(preorder,mini,root->val,i);
        root->right=pre(preorder,root->val,maxi,i);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
       int mini=INT_MIN;
       int maxi=INT_MAX;
       int i=0;
       return pre(preorder,mini,maxi,i); 
    }
};