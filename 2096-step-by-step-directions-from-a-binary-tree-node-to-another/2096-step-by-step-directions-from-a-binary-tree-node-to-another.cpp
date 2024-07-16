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
    TreeNode* LCA(TreeNode* root, int p, int q) {
        if(root==NULL)
        {
            return NULL;
        }
        if(root->val==p || root->val==q)return root;

        TreeNode* leftAns=LCA(root->left,p,q);
        TreeNode* rightAns=LCA(root->right,p,q);

        if(leftAns!=NULL && rightAns!=NULL)return root;
        else if(leftAns!=NULL && rightAns==NULL)return leftAns;
        else if(leftAns==NULL && rightAns!=NULL)return rightAns;
        else return NULL;
    }
    
    bool solve(TreeNode* root,int tar,string &s)
    {
        if(root == NULL)
        {
            return false;
        }
        if(root->val == tar)
        {
            return true;
        }
        
        bool ch1 = solve(root->left,tar,s+='L');
        if(ch1)return true;
        s.pop_back();
        
        bool ch2 = solve(root->right,tar,s+='R');
        if(ch2)return true;
        s.pop_back();
        
        return false;
    }
    
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* baap = root;
        baap = LCA(root,startValue,destValue);
        // cout<<baap->val;
        string s1="",s2="";
        solve(baap,startValue,s1);
        solve(baap,destValue,s2);
        
        cout<<"s1 "<<s1<<" s2 "<<s2<<endl;
        int n = s1.size();
        string s(n,'U');
        return s+s2;
    }
};