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
    void helper(TreeNode* root,int x,int y,map<pair<int,int>,vector<int>> &m)
    {
        if(!root)
            return;
        m[{x,y}].push_back(root->val);
        if(root->left)
            helper(root->left,x-1,y+1,m);
        if(root->right)
            helper(root->right,x+1,y+1,m);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
        vector<vector<int>> res;
        map<pair<int,int>,vector<int>> m;
        helper(root,0,0,m);
        int xmin=m.begin()->first.first;
        vector<int> v;
        for(auto x:m)
        {
            sort(x.second.begin(),x.second.end());
            if(x.first.first!=xmin)
            {
                res.push_back(v);
                xmin=x.first.first;
                v={};
            }
            for(int i:x.second)
                v.push_back(i);
        }
        res.push_back(v);
        return res;
    }
};