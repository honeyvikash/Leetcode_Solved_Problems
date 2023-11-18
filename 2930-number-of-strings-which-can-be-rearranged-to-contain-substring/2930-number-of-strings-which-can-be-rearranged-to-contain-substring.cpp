class Solution {
public: 
    long long dp[100005][3][2][2];
    int mod = 1e9+7;
    long long solve(int idx,int e,int l,int t,int n)
    {
        if(idx==n)
        {
            if(e>=2 && l>=1 && t>=1)
            return 1;
            return 0;
        }
        if(dp[idx][e][l][t]!=-1)
        return dp[idx][e][l][t];
        long long ans = 0;
        for(int i=0;i<26;i++)
        {
            if(i==4 && e<2)
            ans=(ans+solve(idx+1,e+1,l,t,n))%mod;
            else if(i==11 && l<1)
            ans=(ans+solve(idx+1,e,l+1,t,n))%mod;
            else if(i==19 && t<1)
            ans=(ans+solve(idx+1,e,l,t+1,n))%mod;
            else
            ans=(ans+solve(idx+1,e,l,t,n))%mod;
        }
        return dp[idx][e][l][t] = ans;
    }
    int stringCount(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,0,0,n);
    }
};