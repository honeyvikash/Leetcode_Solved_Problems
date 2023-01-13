class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2) return NULL;
        else if(!root1) return root2;
        else if(!root2) return root1;
        queue<pair<TreeNode*, TreeNode*>>q;
        q.push({root1,root2});
        while(!q.empty())
        {
            auto temp=q.front();q.pop();
            temp.first->val+=temp.second->val;

            if(temp.first->left && temp.second->left)
                q.push({temp.first->left, temp.second->left});
            else if(temp.second->left)
                temp.first->left=temp.second->left;

            if(temp.first->right && temp.second->right)
                q.push({temp.first->right,temp.second->right});
            else if (temp.second->right)
                temp.first->right=temp.second->right;
        }
        return root1;
    }
};