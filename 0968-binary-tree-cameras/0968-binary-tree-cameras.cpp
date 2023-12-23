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
 
1st approach that came in mind is to do level order traversal and save that in Array List then add the odd list count i.e 1st, 3rd list to get the minimum camera.
2nd approach is optimization of 1st approach where we don't need to calculate the level order traversal and with dfs.
 
 */
class Solution {
public:
    int cameraCount;
private:
    int dfs(TreeNode* root){

        /*
            -1 = doesn't need camera
             0 = doesn't have camera hence camera is needed
             1 = has camera hence camera is not needed
        */

        if(root == NULL) return -1;

        int leftChild = dfs(root->left);

        int rightChild = dfs(root->right);

        if(leftChild == 0 || rightChild == 0) return ++cameraCount - cameraCount + 1;

        if(leftChild == -1 && rightChild == -1) return 0;
        return -1;
    }
public:
    int minCameraCover(TreeNode* root) {
        cameraCount = 0;
        cameraCount += (dfs(root) == 0); // if root needs a camera 
        return cameraCount;
    }
};