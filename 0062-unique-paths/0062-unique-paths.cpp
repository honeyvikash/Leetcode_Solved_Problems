class Solution {
public:
//     int dp[1000][1000];
//     int solve(int i, int j, int m, int n)
//     {
//         if(i==m-1 && j==n-1)
//         {
//             return dp[i][j]=1;
//         }
//         if(i>=m || j>=n)
//         {
//             return dp[i][j]=0;
//         }
        
//         if(dp[i][j]!=-1)return dp[i][j];
        
//         return dp[i][j]=(solve(i+1,j,m,n)+solve(i,j+1,m,n));
        
//     }
//     int uniquePaths(int m, int n) {
//         memset(dp,-1,sizeof(dp));
//         return solve(0,0,n,m);   
//     }
    
    int solveTab(int m, int n) 
        {
            vector<vector<int>>dp(m,vector<int>(n,0));
            dp[0][0] = 1;
            
            for(int i=1; i<n; i++)
            {
                dp[0][i] = 1;
            }
            
            for(int i=1; i<m; i++)
            {
                dp[i][0] = 1;
            }

            for(int i=1; i<m; i++) 
            {
                for(int j=1; j<n; j++)
                {
                    dp[i][j] = dp[i][j-1] + dp[i-1][j];
                }
            }
            return dp[m-1][n-1];
        }
        int uniquePaths(int m, int n) {
            return solveTab(m,n);
        }
};