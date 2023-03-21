class Solution {
public:
    int sasta(vector<int>& c, int n,vector<int>& dp)
    {
        if(n==0)return c[0];
        if(n==1)return c[1];
        
        if(dp[n]!=-1)return dp[n];
        
        dp[n]=c[n]+min(sasta(c,n-1,dp),sasta(c,n-2,dp));
        return dp[n];
    }
    
    int minCostClimbingStairs(vector<int>& c) {
        int n=c.size();
        vector<int>dp(n+1,-1);
        return min(sasta(c,n-1,dp),sasta(c,n-2,dp));
    }
};