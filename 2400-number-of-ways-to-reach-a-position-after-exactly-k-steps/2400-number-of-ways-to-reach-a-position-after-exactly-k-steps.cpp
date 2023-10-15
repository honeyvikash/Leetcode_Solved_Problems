class Solution {
public:
    int dp[3001][1001];
    int mod = 1e9+7;
    //1000 to handle the negetive case     
    int solve(int idx,int k,int tar)
    {
        if(idx==tar && k==0)
            return 1;
        
        if(abs(abs(idx)-abs(tar))>k)
            return 0;
        
        if(dp[idx+1000][k]!=-1) 
            return dp[idx+1000][k];
        
        int tak1 = solve(idx+1,k-1,tar)%mod;
        int tak2 = solve(idx-1,k-1,tar)%mod;
        
        return dp[idx+1000][k] = (tak1+tak2)%mod;
    }
    int numberOfWays(int startPos, int endPos, int k) {
        memset(dp,-1,sizeof(dp));
        return solve(startPos,k,endPos);
    }
};