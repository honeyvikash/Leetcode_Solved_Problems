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
    int idx=0;
    unordered_map<int,int>m;
    
    TreeNode* solve(vector<int>& pre, vector<int>& in,int l,int h)
    {
        if(l>h) return NULL;
        
        TreeNode* ans = new TreeNode(pre[idx++]);
        
        if(l==h) return ans;
        
        int mid = m[ans->val];
        ans->left = solve(pre,in,l,mid-1);
        ans->right = solve(pre,in,mid+1,h);
        
        return ans;
    }
    
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        //logic: inorder ko use krenge like sub trees me baat pae and pre order ko traverse krenge ek ek krke
        
        idx=0;
        m.clear();
        int n = in.size();
        // store the index for searching in O(1)
        
        for(int i=0;i<n;i++)
        {
            m[in[i]]=i;
        }
        
        TreeNode* root = solve(pre,in,0,n-1);
        return root;
        
    }
};