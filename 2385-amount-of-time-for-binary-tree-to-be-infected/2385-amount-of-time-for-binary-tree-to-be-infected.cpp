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
    map<TreeNode*,TreeNode*> par;
    TreeNode* st;
    void dfs(TreeNode* root,TreeNode* parent,int num)
    {
        if(!root)
        return;
        par[root] = parent;
        if(root->val==num)
        st = root;
        dfs(root->left,root,num);
        dfs(root->right,root,num);
    }
    int amountOfTime(TreeNode* root, int start) {
        dfs(root,NULL,start);
        queue<TreeNode*> q;
        map<TreeNode*,int> vis;
        q.push(st);
        vis[st] = 1;
        int ans = 0;
        while(!q.empty())
        {
            int siz = q.size();
            for(int i=0;i<siz;i++)
            {
                TreeNode* node = q.front();
                q.pop();
                if(node->left && !vis[node->left])
                {
                    vis[node->left] = 1;
                    q.push(node->left);
                }
                if(node->right && !vis[node->right])
                {
                    vis[node->right] = 1;
                    q.push(node->right);
                }
                if(par[node]!=NULL && !vis[par[node]])
                {
                    vis[par[node]] = 1;
                    q.push(par[node]);   
                }
            }
            ans++;
        }
        return ans-1;
    }
};