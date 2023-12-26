class Solution {
public:
    int mod = 1e9+7;
    long long dp[32][1001];
    int solve(int n,int csum,int k)
    {
        if(csum==0 && n==0)
        return 1;
        if(n==0)
        return 0;
        if(dp[n][csum]!=-1)
        return dp[n][csum];
        long long ans = 0;
        for(int i=1;i<=k;i++)
        {
            if(csum-i>=0)
            ans = (ans+solve(n-1,csum-i,k));
        }
        return dp[n][csum] = ans%mod;
    }
    int numRollsToTarget(int n, int k, int target) {
        memset(dp,-1,sizeof(dp));
        return solve(n,target,k);
    }
};