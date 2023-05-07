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
    int ans=0;
    
    void solve(TreeNode* root,vector<int>& v)
    {
        if(root==NULL)return;
        v[root->val]++;
        
        solve(root->left,v);
        solve(root->right,v);
        
        if(root->left==NULL && root->right==NULL)
        {
            int cnt=0;
            for(int i=1;i<=9;i++)
            {
                if(v[i]%2!=0)cnt++;
            }
            if(cnt==1 || cnt==0)ans++; 
        }
        
        //backtrack
        v[root->val]--;
        
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int>v(10,0);
        solve(root,v);
        return ans;
    }
};