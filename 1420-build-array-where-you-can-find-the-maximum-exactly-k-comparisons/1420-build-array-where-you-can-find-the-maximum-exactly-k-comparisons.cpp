#define ll long long
class Solution {
public:
    int dp[51][105][105];
    int mod = 1e9+7;
    int solve(ll n,ll cMax,ll cntMax,ll k,ll m)
    {
        if(n==0 && cntMax==k)
            return 1;
        else if(n==0)
            return 0;
        if(dp[n][cMax][cntMax]!=-1)
            return dp[n][cMax][cntMax];

        ll ans = 0;
        if(cntMax<k)
        {
            for(int i=cMax;i<=m;i++)
            {
                if(k-(cntMax+1)<=m)
                ans=(ans+solve(n-1,i+1,cntMax+1,k,m))%mod;
            }
        }
            ans=(ans+(cMax-1)*(solve(n-1,cMax,cntMax,k,m)))%mod;
        return dp[n][cMax][cntMax] = ans%mod;
    }
    int numOfArrays(int n, int m, int k) {
        memset(dp,-1,sizeof(dp));
        if(m<k)
        return 0;
        return solve(n,1,0,k,m);
    }
};