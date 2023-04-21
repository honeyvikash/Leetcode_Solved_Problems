class Solution {
public:
    int dp[104][104][104];
    int mod = 1e9+7;
    int solve(int idx,int prof,int ppl,vector<int>& profit,vector<int>& grps,int minP)
    {
        if(idx==grps.size())
        {
            if(prof>=minP)
            return 1;
            return 0;
        }
        if(dp[idx][ppl][prof]!=-1)
        return dp[idx][ppl][prof];
        int tak = 0;
        if(ppl-grps[idx]>=0)
        {
            tak = solve(idx+1,min(minP,prof+profit[idx]),ppl-grps[idx],profit,grps,minP);
        }
        int notTake = solve(idx+1,prof,ppl,profit,grps,minP);
        return dp[idx][ppl][prof] = (tak+notTake)%mod;
    }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,n,profit,group,minProfit);
    }
};