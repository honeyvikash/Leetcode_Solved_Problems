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
    int ans;
public:
    Solution():ans(0){}
    int helper(TreeNode *root,bool isLeftMove){
        if( NULL==root )    return 0;
        if( isLeftMove ){
            ans = max(ans,helper(root->left,true));
            return helper(root->right,false)+1;
        }else{
            ans = max(ans,helper(root->right,false));
            return helper(root->left,true)+1;
        }
    }
    int longestZigZag(TreeNode* root) {
        ans = max({helper(root->left,true),helper(root->right,false),ans});
        return ans;
    }
};