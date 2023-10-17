class Solution {
public:
    bool ans;
    void dfs(int node,vector<int>& lc,vector<int>& rc,vector<int>& vis)
    {
        if(node==-1)
        return;
        if(vis[node]==1)
        {
            ans = false;
            return;
        }
        else
        vis[node] = 1;
        dfs(lc[node],lc,rc,vis);
        dfs(rc[node],lc,rc,vis);
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        ans = true;
        vector<int> vis(n);
        vector<int> tmp(n,-1);
        for(int i=0;i<n;i++)
        {
            if(leftChild[i]!=-1)
            tmp[leftChild[i]] = 0;
            if(rightChild[i]!=-1)
            tmp[rightChild[i]] = 0;
        }
        int root = -1;
        for(int i=0;i<n;i++)
        {
            if(tmp[i]==-1)
            {
                root = i;
                break;
            }
        }
        if(root==-1)
        return false;
        dfs(root,leftChild,rightChild,vis);
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            return false;
        }
        return ans;
    }
};