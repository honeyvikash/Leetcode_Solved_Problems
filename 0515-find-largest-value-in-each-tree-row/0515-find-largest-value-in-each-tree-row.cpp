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
    vector<int> largestValues(TreeNode* root) {
        LOT(root);
        if(root==NULL)
        {
            return {};
        } 
        vector<int>v;
        for(int i=0;i<ans.size();i++)
        {
            int m=*max_element(ans[i].begin(),ans[i].end());
            v.push_back(m);
        }
        return v;
    }
};