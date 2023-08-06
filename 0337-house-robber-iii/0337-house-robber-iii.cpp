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
class Solution
{
public:
    map<TreeNode *, int> robbed;
    map<TreeNode *, int> not_robbed;
    int help(TreeNode *root, bool b)
    {
        if (root == NULL)
            return 0;
        if (b)
        {
            if (robbed[root] == 0)
            {
                robbed[root] = help(root->left, false) + help(root->right, false);
                return (help(root->left, false) + help(root->right, false));
            }
            else
            {
                return robbed[root];
            }
        }
        if (not_robbed[root] == 0)
        {
            not_robbed[root] = max(root->val + help(root->left, true) + help(root->right, true), help(root->left, false) + help(root->right, false));
        }
        return (not_robbed[root]);
    }
    int rob(TreeNode *root)
    {
        return help(root, false);
    }
};