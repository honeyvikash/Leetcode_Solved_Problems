class Solution {
public:
    int dp[101][101];
    int solve(int x,int y,vector<vector<int>>& grid)
    {
        if(x==0 && y==0 && grid[x][y]!=1)
            return 1;
        if(x<0 || y<0)
            return 0;
        if(grid[x][y]==1)
            return 0;
        if(dp[x][y]!=-1)
            return dp[x][y];
        return dp[x][y] = solve(x-1,y,grid)+solve(x,y-1,grid);
    }
    int solveTab(vector<vector<int>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp( n , vector<int> (m, 0));
        // dp[0][0]=1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                // dp[i][j]=dp[i-1][j]+dp[i][j-1];
                if (grid[i][j]==1)
                {
                    dp[i][j]=0;
                }
                else if (i==0 && j==0) 
                {
                    dp[i][j]=1;
                }
                else
                {
                    // if(i>0)dp[i][j]+=dp[i-1][j];
                    // if(j>0)dp[i][j]+=dp[i][j-1];
                    int up=0;
                    int left=0;
                    if (i>0) up=dp[i-1][j];
                    if (j>0) left=dp[i][j-1];
                    dp[i][j]=up+left;
                }
            }
        }
        return dp[n-1][m-1];
        
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        if(grid[n-1][m-1]==1 || grid[0][0]==1)
            return 0;
        
        // memset(dp,-1,sizeof(dp));
        // return solve(n-1,m-1,grid);
        return solveTab(grid);
    }
};