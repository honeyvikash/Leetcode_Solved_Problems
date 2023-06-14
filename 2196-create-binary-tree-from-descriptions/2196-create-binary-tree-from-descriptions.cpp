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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        TreeNode *res = nullptr;
        unordered_map<int, TreeNode*> nodes;
        unordered_map<int, int> parents;

        for (vector<int> &d : descriptions)
        {
            int par = d[0], ch = d[1], isLeft = d[2];
            TreeNode *parent = nullptr, *child = nullptr;
            
            if (!nodes.count(par))
            {
                parent = new TreeNode(par);
                nodes[par] = parent;
            }
            else
                parent = nodes[par];
            if (!nodes.count(ch))
            {
                child = new TreeNode(ch);
                nodes[ch] = child;
            }
            else
                child = nodes[ch];

            parents[ch] = par;

            if (isLeft)
                parent->left = child;
            else
                parent->right = child;
        }
        for (auto [val, node] : nodes)
        {
            if (!parents.count(val))
                res = node;
        }
        return res;
    }
};