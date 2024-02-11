class Solution {
public:
    int dp[70][70][70];
    bool isValid(int c1,int c2,int m)
    {
        if(c1>=0 && c1<m && c2>=0 && c2<m) return true;
        return false;
    }
    int solve(int r,int c1,int c2,vector<vector<int>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        if(r==n) return 0;
        
        if(dp[r][c1][c2]!=-1) return dp[r][c1][c2];
        int ans = 0;
        for(int i=-1;i<=1;i++)
        {
            for(int j=-1;j<=1;j++)
            {
                int newC1 = c1+i,newC2 = c2+j;
                if(isValid(newC1,newC2,m))
                {
                    ans = max(ans,solve(r+1,newC1,newC2,grid));   
                }
            }
        }
        int cherry = c1==c2?grid[r][c1]:grid[r][c1]+grid[r][c2];
        return dp[r][c1][c2] = ans+cherry;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        int m = grid[0].size();
        return solve(0,0,m-1,grid);
    }
};