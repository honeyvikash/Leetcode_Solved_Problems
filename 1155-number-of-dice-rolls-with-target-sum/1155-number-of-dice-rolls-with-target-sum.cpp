class Solution {
public:
    #define ll long long 
    
    int mod = 1e9+7;
    
    int solve(int n, int k, int t, vector<vector<ll>> &dp)
    {
        if(t<0)return 0;
        if(n==0 and t!=0)return 0;
        if(n!=0 and t==0)return 0;
        if(n==0 and t==0)return 1;
        
        if(dp[n][t]!=-1)return dp[n][t];
        
        ll ans = 0;
        for(int i =1 ;i<=k; i++)
        {
            ans += solve(n-1,k,t-i,dp);
        }
        
        return dp[n][t] = ans%mod;
    }
    int numRollsToTarget(int n, int k, int t) {
        vector<vector<ll>>dp(n+1,vector<ll>(t+1,-1));
        return solve(n,k,t,dp);
    }
};