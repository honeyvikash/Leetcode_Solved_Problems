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
    vector<vector<int>>ans;
    void LOT(TreeNode* &root)
    {
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int n = q.size();
            vector<int>temp;
            while (n--)
            {
                TreeNode* node = q.front();
                q.pop();
                if(node!=NULL)
                {
                    temp.push_back(node->val);
                    if (node->left)
                    {
                        q.push(node->left);
                    }
                    if (node->right)
                    {
                        q.push(node->right);
                    }
                }
                
            }
            ans.push_back(temp);
            temp.clear();
            
        }
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
       LOT(root);
        if(root==NULL)
        {
            return {};
        }
        reverse(ans.begin(),ans.end());
        return ans; 
    }
};