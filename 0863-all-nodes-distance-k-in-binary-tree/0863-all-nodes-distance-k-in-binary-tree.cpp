/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int>graph[500],ans;
    void GraphBuilding(TreeNode *root,TreeNode * par)
    {
        if(root and par)
        {
            graph[root->val].push_back(par->val);
            graph[par->val].push_back(root->val);
        }
        if(root->left)
        {
            GraphBuilding(root->left,root);
        }
        if(root->right)
        {
            GraphBuilding(root->right,root);
        }
    }
    
    void dfs(int t, vector<int>&vis,int cnt, int k)
    {
        if(cnt==k)
        {
            ans.push_back(t);
            return;
        }
        
        vis[t]=1;
        
        for(auto i:graph[t])
        {
            if(!vis[i])
            {
                dfs(i,vis,cnt+1,k);
            }
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>vis(500,0);
        GraphBuilding(root,NULL);
        dfs(target->val,vis,0,k);
        return ans;
    }
};