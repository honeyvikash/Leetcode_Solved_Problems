class Solution {
public:
    
    int solve(vector<int>& a,int n,vector<int>& dp)
    {
        if(n<0)return 0;
        
        if(n==0) return a[0];
        
        if(dp[n]!=-1)return dp[n];
        
        int include = solve(a,n-2,dp)+a[n];
        int exclude = solve(a,n-1,dp)+0;
        
        return dp[n]=max(include,exclude);
    }
    
    int rob(vector<int>& a) {
        vector<int>dp(a.size()+1,-1);
        return solve(a,a.size()-1,dp);
    }
};