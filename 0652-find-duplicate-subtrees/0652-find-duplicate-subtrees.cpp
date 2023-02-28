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
    map<string,int>m;
    string find(TreeNode* root,vector<TreeNode*>&ans)
    {
        if(root==NULL)return "";
        string temp = find(root->left,ans)+","+find(root->right,ans)+","+to_string(root->val);
        m[temp]++;
        if(m[temp]==2)ans.push_back(root);
        return temp;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*>ans;
        find(root,ans);
        return ans;
    }
};