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
    int move = 0;
    int solve(TreeNode* root)
    {
        if(root==NULL)return 0;
        int le = solve(root->left);
        int ri = solve(root->right);
        move += abs(le)+abs(ri);
        return (root->val+le+ri)-1;
    }
    int distributeCoins(TreeNode* root) {
        solve(root);
        return move;
    }
};