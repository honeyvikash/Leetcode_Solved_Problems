class Solution {
public:
    int dp[201][201];
    int mod = 1e9+7;
    int solve(int idx,vector<int>& loc,int fuel,int fin)
    {
        int ans = 0;
        if(idx==fin && fuel>=0) ans++;
        
        if(dp[idx][fuel]!=-1) return dp[idx][fuel];
        
        for(int i=0;i<loc.size();i++)
        {
            if(i!=idx && (fuel-abs(loc[i]-loc[idx]))>=0)
            ans = (ans+solve(i,loc,fuel-abs(loc[i]-loc[idx]),fin))%mod;
        }
        return dp[idx][fuel] = ans;
    }
    int countRoutes(vector<int>& loc, int start, int finish, int fuel) {
        memset(dp,-1,sizeof(dp));
        return solve(start,loc,fuel,finish);
    }
};