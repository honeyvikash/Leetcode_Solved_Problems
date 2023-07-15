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
    void solve(TreeNode* root, int& ans, int val)
    {
        if(root == NULL) return;
        if(root->left == NULL and root->right == NULL)
        {
            val = val << 1;
            if(root->val == 1) val += 1;
            ans += val;
            return;
        }
        val = val << 1;
        if(root->val == 1) val += 1;
        solve(root->left, ans, val);
        solve(root->right, ans, val);
    }
    int sumRootToLeaf(TreeNode* root) {
        int ans = 0;
        solve(root, ans, 0);
        return ans;
    }
};