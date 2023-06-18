class Solution {
public:
    int mod = 1e9+7;
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    int dp[1001][1001];
    bool isValid(int x,int y,int n,int m)
    {
        if(x>=0 && y>=0 && x<n && y<m)
        return true;
        return false;
    }
    int dfs(int x,int y,vector<vector<int>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        if(dp[x][y]!=-1)
        return dp[x][y];
        int ans = 1;
        for(int i=0;i<4;i++)
        {
            int newX = x+dx[i];
            int newY = y+dy[i];
            if(isValid(newX,newY,n,m) && grid[newX][newY]>grid[x][y])
            {
                ans=(ans+dfs(newX,newY,grid))%mod;
            }
        }
        return dp[x][y] = ans;
    }
    int countPaths(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        int ans=0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                ans=(ans+dfs(i,j,grid))%mod;
            }
        }
        return ans;
    }
};