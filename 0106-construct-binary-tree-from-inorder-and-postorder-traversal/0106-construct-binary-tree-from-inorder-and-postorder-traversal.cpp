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
    TreeNode* solve(vector<int>& post,map<int,int>& idx,int inSt,int inEn,int &postInd)
    {
        if(inSt>inEn)
            return NULL;
        TreeNode* root = new TreeNode(post[postInd]);
        int ind = idx[post[postInd]];
        postInd--;
        root->right = solve(post,idx,ind+1,inEn,postInd);
        root->left = solve(post,idx,inSt,ind-1,postInd);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int> idx;
        for(int i=0;i<inorder.size();i++)
        {
            idx[inorder[i]] = i;
        }
        int n = postorder.size();
        int postInd = n-1;
        return solve(postorder,idx,0,n-1,postInd);
    }
};