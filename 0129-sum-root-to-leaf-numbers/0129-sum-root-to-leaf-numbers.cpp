class Solution {
public:
    int helper(TreeNode *root,int num){
        if( NULL==root )    return 0;
        num = num*10+root->val;
        if( NULL==root->left && NULL==root->right ) return num;
        return ( helper(root->left,num)+helper(root->right,num) );
    }
    int sumNumbers(TreeNode* root) {
        return helper(root,0) ;
    }
};


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