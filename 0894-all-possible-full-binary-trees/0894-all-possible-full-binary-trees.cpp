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
    unordered_map<int,vector<TreeNode*>> m;
    vector<TreeNode*> solve(int n)
    {
        if(n<=0 || n%2==0)
            return {};
        if(n==1)
            return {new TreeNode(0)};
        if(m.find(n)!=m.end())
            return m[n];
        vector<TreeNode*> trees;
        for(int i=1;i<n;i+=2)
        {
            vector<TreeNode*> left=solve(i);
            vector<TreeNode*> right=solve(n-i-1);
            for(int j=0;j<left.size();j++)
            {
                for(int k=0;k<right.size();k++)
                {
                    TreeNode* root=new TreeNode(0);
                    root->left=left[j];
                    root->right=right[k];
                    trees.push_back(root);
                }
            }
        }
        return m[n]=trees;
    }
    vector<TreeNode*> allPossibleFBT(int n) {
        m.clear();
        return solve(n);
    }
};