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
    void dfs(TreeNode* root, string s, string & sol)
    {
        if(root!=NULL)
        {
            s.push_back('a' + root->val);
            if(root->left == NULL && root->right == NULL)
            {
                string str ="";
                for(int i = s.length()-1;i>=0;i--)
                {
                    str.push_back(s[i]);
                }
                if(str < sol)
                {
                    sol = str;
                }
            }
            dfs(root->left, s,sol);
            dfs(root->right,s, sol);
            s.pop_back();
        }

    }
    string smallestFromLeaf(TreeNode* root) {
        string sol = "zzzzzzzzzzz";
        dfs(root,"",sol);
        return sol;
    }
};