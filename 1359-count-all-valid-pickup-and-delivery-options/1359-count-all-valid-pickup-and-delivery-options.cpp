class Solution {
public:
    int mod = 1e9+7;
    long long dp[1002];
    int solve(long long n)
    {
        if(n==2)
            return 1;
        if(dp[n]!=-1)
            return dp[n]%mod;
        return dp[n] = ((((n%mod*(n-1)%mod)/2)%mod)*(solve(n-2)%mod))%mod;
    }
    int countOrders(int n) {
        memset(dp,-1,sizeof(dp));
        n*=2;
        return solve(n);
    }
};