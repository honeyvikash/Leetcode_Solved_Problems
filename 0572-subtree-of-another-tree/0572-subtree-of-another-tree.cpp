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
    bool same(TreeNode* a, TreeNode* b)
    {
        if(a==NULL and b==NULL)return true;
        if(a==NULL || b==NULL)return false;
        if(a->val!=b->val)return false;
        return same(a->left,b->left) and same(a->right,b->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL)return false;
        TreeNode* x= new TreeNode(root->val,root->left, root->right);
        TreeNode* y= new TreeNode(subRoot->val,subRoot->left, subRoot->right);
        if(same(x,y))return true;
        return ( isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot));
    }
};