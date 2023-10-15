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
    vector<int> ans;
    bool solve(TreeNode* root,vector<int>& voy,int& pos)
    {
        if(root==NULL)
            return true;
        if(root->val!=voy[pos++])
            return false;
        TreeNode* l = root->left;
        TreeNode* r = root->right;
        if(l && l->val!=voy[pos])
        {
            ans.push_back(root->val);
            swap(l,r);
        }
        return solve(l,voy,pos) && solve(r,voy,pos);
    }
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        int ptr = 0;
        if(solve(root,voyage,ptr))
            return ans;
        return {-1};
    }
};