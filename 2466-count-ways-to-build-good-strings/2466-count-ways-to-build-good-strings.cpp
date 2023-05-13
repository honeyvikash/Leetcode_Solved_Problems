class Solution {
public:
    int dp[100001];
    int mod = 1e9+7;
    int solve(int low,int high,int zero,int one,int clen)
    {
        if(clen>high) return 0;
        
        if(dp[clen]!=-1) return dp[clen];
       
        int ans = 0;
        
        if(clen>=low && clen<=high) ans++;
        
        int take1 = solve(low,high,zero,one,clen+zero);
        int take2 = solve(low,high,zero,one,clen+one);
        return dp[clen] = (ans+take1+take2)%mod;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        memset(dp,-1,sizeof(dp));
        return solve(low,high,zero,one,0);
    }
};