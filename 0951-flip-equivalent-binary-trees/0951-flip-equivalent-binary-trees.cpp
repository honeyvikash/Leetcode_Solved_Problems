class Solution {
public:
    bool isIdentical(TreeNode* root1, TreeNode* root2)
    {
        if(root1==NULL && root2==NULL)return true;
        if(root1==NULL || root2==NULL || root1->val!=root2->val)return false;
        bool l_Identical=isIdentical(root1->left,root2->left);
        bool r_Identical=isIdentical(root1->right,root2->right);

        if(l_Identical && r_Identical)return true;

        bool leftFlipIdentical = isIdentical(root1->right, root2->left);
        bool rightFlipIdentical = isIdentical(root1->left, root2->right);
            return leftFlipIdentical && rightFlipIdentical;

        return false;
    }
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        // Considering this
        // A binary tree X is flip equivalent to a binary tree Y if and only if we can make X equal to Y after some number of flip operations.

        return isIdentical(root1,root2);

    }
};