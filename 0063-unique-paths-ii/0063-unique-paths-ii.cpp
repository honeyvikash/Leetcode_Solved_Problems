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
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(grid[n-1][m-1]==1 || grid[0][0]==1)
            return 0;
        memset(dp,-1,sizeof(dp));
        return solve(n-1,m-1,grid);
    }
};