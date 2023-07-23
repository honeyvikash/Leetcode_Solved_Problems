class Solution {
public:
    int fun(vector<vector<int>>&t,int n,int i,int j,vector<vector<int>>&dp)
    {
        if(i>=t.size())  return 0;
         
        if(dp[i][j]!=-1)return dp[i][j];
        
        int x=INT_MAX;
        int y=INT_MAX;
        if(i<n and j<t.size())
        {
            x=t[i][j]+fun(t,n,i+1,j,dp);
            y=t[i][j]+fun(t,n,i+1,j+1,dp);
        }  
        return dp[i][j]=min(x,y);
        
    }
    int minimumTotal(vector<vector<int>>& t) {
//         int sum=triangle[0][0];
        
//         sum+=fun(triangle,1,0);
        int n = t.size();
        int m = t[n-1].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        
        return fun(t,n,0,0,dp);
    }
};