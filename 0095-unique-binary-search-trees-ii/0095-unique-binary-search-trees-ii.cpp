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
    vector<TreeNode*> solve(int start,int end)
    {
        vector<TreeNode*> v;
        if(start==end)
        {
            TreeNode* root = new TreeNode(start);
            v.push_back(root);
            return v;
        }
        if(start>end)
        {
            v.push_back(NULL);
            return v;
        }
        for(int i=start;i<=end;i++)
        {
            auto left = solve(start,i-1);
            auto right = solve(i+1,end);
            for(auto l:left)
            {
                for(auto r:right)
                {
                    TreeNode* root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    v.push_back(root);
                }
            }
        }
        return v;
    }
    vector<TreeNode*> generateTrees(int n) {
        return solve(1,n);
    }
};