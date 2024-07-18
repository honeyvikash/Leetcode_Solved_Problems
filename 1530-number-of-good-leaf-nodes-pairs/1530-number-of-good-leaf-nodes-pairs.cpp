/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* mainRoot = NULL;
    map<TreeNode*, vector<TreeNode*>> mp;
    void makeGraph(TreeNode* root, TreeNode* parent) 
    {
        if (!root)
            return;

        if (parent)
            mp[root].push_back(parent);

        if (root->left) 
        {
            mp[root].push_back(root->left);
            makeGraph(root->left, root);
        }

        if (root->right) 
        {
            mp[root].push_back(root->right);
            makeGraph(root->right, root);
        }
    }
    int dfs(TreeNode* root, TreeNode* par, int dist) 
    {
        if (dist < 0)
            return 0;

        if (mp[root].size() == 1 && par!=NULL && root!=mainRoot) 
        {
            return 1;
        }

        int ans = 0;

        for (auto ne : mp[root])
            if (ne != par) {
                ans += dfs(ne, root, dist - 1);
            }

        return ans;
    }
    int countPairs(TreeNode* root, int dist) {
        mainRoot = root;
        makeGraph(root, NULL);
        int ans = 0;
        for (auto [a, b] : mp)
            if (b.size() == 1 && a!=mainRoot) 
            {
                int x = dfs(a, NULL, dist);
                ans += x;
            }
        return ans>>1;
    }
};