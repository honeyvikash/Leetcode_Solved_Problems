class Solution {
public:
    int dx[8] = {-1,-2,-2,-1,1,2,2,1};
    int dy[8] = {2,1,-1,-2,2,1,-1,-2};
    bool isValid(int x,int y,int n)
    {
        if(x>=0 && x<n && y>=0 && y<n)
            return true;
        return false;
    }
    double solve(int r,int c,int k,int n,vector<vector<vector<double>>>&dp)
    {
        if(r>=n || c>=n)
            return 0;
        if(k==0)
            return 1;
        if(dp[r][c][k]!=-1)
            return dp[r][c][k];
        double ans = 0;
        for(int i=0;i<8;i++)
        {
            int newx = r+dx[i];
            int newy = c+dy[i];
            if(isValid(newx,newy,n))
            {
                ans+=solve(newx,newy,k-1,n,dp)/8;
            }
        }
        return dp[r][c][k] = ans;
    }
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> dp(26,vector<vector<double>>(26,vector<double>(101,-1)));
        return solve(row,column,k,n,dp);
    }
};