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
    int cnt = 0;
    bool check(vector<int>&v)
    {
        int tmp_cnt = 0;
        for(auto &i:v)
        {
            tmp_cnt+=i%2;
        }
        return tmp_cnt<2;
    }
    void dfs(TreeNode* root,vector<int>&v)
    {
        if(root->left == NULL && root->right == NULL)
        {
            if(check(v))cnt++;
            return;
        }
        if(root->left != NULL)
        {
            v[root->left->val]++;
            dfs(root->left,v);
            v[root->left->val]--;
        }
        if(root->right != NULL)
        {
            v[root->right->val]++;
            dfs(root->right,v);
            v[root->right->val]--;
        }
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int>v(10);
        v[root->val]=1;
        dfs(root,v);
        return cnt;
    }
};