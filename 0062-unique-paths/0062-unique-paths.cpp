class Solution {
public:
    int dp[1000][1000];
    int solve(int i, int j, int m, int n)
    {
        if(i==m-1 && j==n-1)
        {
            return dp[i][j]=1;
        }
        if(i>=m || j>=n)
        {
            return dp[i][j]=0;
        }
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        return dp[i][j]=(solve(i+1,j,m,n)+solve(i,j+1,m,n));
        
    }
    int uniquePaths(int m, int n) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,n,m);   
    }
};