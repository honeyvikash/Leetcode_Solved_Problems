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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});
        int ans = 0;
        while(!q.empty())
        {
            int siz = q.size();
            long long fir,las;
            long long mini = q.front().second;
            for(int i=0;i<siz;i++)
            {
                TreeNode* node = q.front().first;
                long long value = q.front().second;
                long long ind = value-mini;
                q.pop();
                if(i==0)
                fir = value;
                if(i==siz-1)
                las = value;
                if(node->left)
                {
                    q.push({node->left,2*ind+1});
                }
                if(node->right)
                {
                    q.push({node->right,2*ind+2});
                }
            }
            ans = max((long long)ans,las-fir+1);
        }
        return ans;
    }
};