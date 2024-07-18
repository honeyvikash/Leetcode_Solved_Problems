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
    void markParent(TreeNode* root , 
    unordered_map<TreeNode*,TreeNode*> &parent)
    {
        if(root==NULL) return ;

        queue<TreeNode*>q ;
        q.push(root) ;
        parent[root]=NULL ;

        while(!q.empty())
        {
            TreeNode* node = q.front() ;
            q.pop() ;

            if(node->left!=NULL)
            {
                parent[node->left] = node ;
                q.push(node->left) ;
            }   

            if(node->right!=NULL)
            {
                parent[node->right]= node ;
                q.push(node->right) ;
            }
        }
    }

    void helper(TreeNode* root, vector<TreeNode*>&leaf)
    {
        if(root==NULL)
        {
            return ;
        }
        helper(root->left,leaf) ;
        if(root->left==NULL && root->right==NULL)
        {
            leaf.push_back(root) ;
        } 
        helper(root->right,leaf) ;
    }

    int countPairs(TreeNode* root, int distance) {
        vector<TreeNode*> leaf ;
        unordered_map<TreeNode*,TreeNode*> parent ;
        markParent(root,parent) ;

        helper(root,leaf) ;

        int cnt = 0 ;

        for(auto it : leaf)
        {
            queue<TreeNode*>q ;
            q.push(it) ;

            //if(it->val==5) cout<<"hi"<<cnt<<endl;

            unordered_map<TreeNode*,int> vis ;
            vis[it]=1 ;

            int level = 1 ;

            while(!q.empty())
            {
                int siz=q.size() ;
                while(siz--)
                {
                    TreeNode* node = q.front() ;
                    q.pop() ;
                    //if(it->val==4 || it->val==5) cout<<node->val<< " " <<cnt<<endl;

                    if(node->left!=NULL && !vis[node->left])
                    {
                        vis[node->left]=1 ;
                        q.push(node->left) ;

                        if(node->left->left==NULL && node->left->right==NULL) cnt++ ;
                    }

                    if(node->right!=NULL && !vis[node->right])
                    {
                        vis[node->right]=1 ;
                        q.push(node->right) ;
                        if(node->right->left==NULL && node->right->right==NULL) cnt++ ;
                    }

                    if(parent[node]!=NULL && !vis[parent[node]])
                    {
                        vis[parent[node]]=1 ;
                        q.push(parent[node]) ;
                        if(parent[node]->left==NULL && parent[node]->right==NULL) cnt++ ;
                    }
                }

                level++ ;
                if(level>distance) break ;
            }
        }

        int ans = cnt/2 ;
        return ans ;
    }
};