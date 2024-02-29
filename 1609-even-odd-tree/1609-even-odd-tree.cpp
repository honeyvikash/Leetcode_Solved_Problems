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
    int height(TreeNode* root)
    {
        if(root==NULL)return 0;
        return max(height(root->left),height(root->right))+1;
    }
    vector<int>preData;
    bool check(TreeNode* root,int level)
    {
        if(root==NULL)
        {
            return true;
        }
        if(level%2==0)
        {
            if(root->val%2==0)
            {
                return false;
            }
            if(preData[level]>=root->val)
            {
                return false;
            }
            preData[level]=root->val;
        }
        else
        {
            if(root->val%2==1)
            {
                return false;
            }
            if(preData[level]<=root->val)
            {
                return false;
            }
            preData[level]=root->val;
        }
        return (check(root->left,level+1) && check(root->right,level+1));
    }
    bool isEvenOddTree(TreeNode* root) {
        int h=height(root);
        preData.reserve(h);
        for(int i=0;i<h;i++)
        {
            if(i%2==0)
            {
                preData[i]=INT_MIN;
            }
            else
            {
                preData[i]=INT_MAX;
            }
        }
        return check(root,0);

    }
};