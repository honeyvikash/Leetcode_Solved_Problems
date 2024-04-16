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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        queue<TreeNode*> q;
        int d=1;
        TreeNode* dummy = new TreeNode(0);
        dummy->left = root;
        q.push(dummy);
        while (!q.empty() && d<=depth)
        {
            if (d==depth)
            {
                while (!q.empty())
                {
                    auto t = q.front();
                    t->left = new TreeNode(val,t->left,nullptr);
                    t->right = new TreeNode(val,nullptr,t->right);
                    q.pop();
                }
            }
            else
            {
                int sz=q.size();
                for (int i=0;i<sz;i++)
                {
                    auto t = q.front();
                    if (t->left) q.push(t->left);
                    if (t->right) q.push(t->right);
                    q.pop();
                }
            }
            d++;
        }
        return dummy->left;
    }
};