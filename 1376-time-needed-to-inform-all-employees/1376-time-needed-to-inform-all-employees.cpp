class Solution {
public:
    void dfs(int x,vector<vector<int>>& adj,int &ans,int cTime,vector<int>& in)
    {
        ans = max(ans,cTime);
        for(auto &i:adj[x])
        {
            dfs(i,adj,ans,cTime+in[x],in);
        }
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& inform) {
        vector<vector<int>> adj(n);
        int ans = 0;
        for(int i=0;i<manager.size();i++)
        {
            int par = manager[i];
            if(par!=-1)
            adj[par].push_back(i);
        }
        dfs(headID,adj,ans,0,inform);
        return ans;
    }
};