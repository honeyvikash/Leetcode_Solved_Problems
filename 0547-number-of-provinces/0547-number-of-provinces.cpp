class Solution {
public:
    void dfs(vector<vector<int>>&isConnected,int i,vector<int>&Visited,int n)
    {
        if(Visited[i]==1)
            return;
        Visited[i]=1;
        for(int j=0;j<n;j++)
        {
            if(isConnected[i][j]==1)
            {
                dfs(isConnected,j,Visited,n);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int>Visited(n,0);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(Visited[i]==0)
            {
                ans++;
                dfs(isConnected,i,Visited,n);
            }
        }
        return ans;
    }
};