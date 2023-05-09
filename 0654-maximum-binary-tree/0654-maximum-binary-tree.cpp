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
    int maxi(vector<int>& a,int s, int e)
    {
        int maxa = INT_MIN;
        int index = -1;
        for(int i = s; i <= e; i++)
        {
            if(a[i] > maxa)
            {
                maxa = a[i]; 
                index = i;
            }
        }

        return index;
    }
     
    TreeNode* construct(vector<int>& a,int s, int e)
    {
        if(s>e)return NULL;
        if(s==e)return (new TreeNode(a[s]));
        
        int idx = maxi(a,s,e);
        
        TreeNode* root = new TreeNode(a[idx]); 
        root->left = construct(a,s,idx-1); 
        root->right = construct(a,idx+1,e); 
        
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& a) {
        int n = a.size();
        TreeNode* root = construct(a,0,n-1);
        return root;
    }
};