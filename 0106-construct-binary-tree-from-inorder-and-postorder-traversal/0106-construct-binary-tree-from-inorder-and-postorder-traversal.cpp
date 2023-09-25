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
    TreeNode* solve(vector<int>& post,int is,int ie,unordered_map<int,int>&m,int &pe)
    {
        if(is>ie)
            return NULL;
        TreeNode* root = new TreeNode(post[pe]);
        int idx = m[post[pe]];
        pe--;
        root->right = solve(post,idx+1,ie,m,pe);
        root->left = solve(post,is,idx-1,m,pe);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int>m;
        for(int i=0;i<inorder.size();i++)
        {
            m[inorder[i]] = i;
        }
        int n = postorder.size();
        int pe = n-1;
        return solve(postorder,0,n-1,m,pe);
    }
};