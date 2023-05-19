class Solution {
public:
    bool dfs(int x,vector<vector<int>>& adj,vector<int>& col,int c)
    {
        col[x] = c;
        for(auto &i:adj[x])
        {
            if(col[i]==-1)
            {
                if(!dfs(i,adj,col,!c))
                return false;
            }
            if(col[i]==c)
            return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> col(n,-1);
        for(int i=0;i<n;i++)
        {
            if(col[i]==-1)
            {
                if(!dfs(i,adj,col,0))
                return false;
            }
        }
        return true;
    }
};