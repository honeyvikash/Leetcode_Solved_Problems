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
    
    void inorder(vector<int>& v,TreeNode* root)
    {
        if(root==NULL)
        {
            return;
        }
        inorder(v,root->left);
        v.push_back(root->val);
        inorder(v,root->right);
    }
    
    int getMinimumDifference(TreeNode* root) {
        vector<int>v;
        inorder(v,root);
        sort(v.begin(),v.end());
        int mi = INT_MAX;
        for(int i=1;i<v.size();i++)
        {
            mi=min(mi,abs(v[i]-v[i-1]));
        }
        return mi;
        
    }
};