class Solution {
public:
    int dp[301][5001];
    int solve(int idx,int amount,vector<int>& coins)
    {
        if(amount==0)
            return 1;
        if(amount<0 || idx>=coins.size())
            return 0;
        if(dp[idx][amount]!=-1) return dp[idx][amount];
            
        int tak1 = 0,tak2 = 0;
        
        if(amount-coins[idx]>=0)
            tak1 = solve(idx,amount-coins[idx],coins);
            tak2 = solve(idx+1,amount,coins);
        return dp[idx][amount] = tak1+tak2;  
    }
    int change(int amount, vector<int>& coins) {
        memset(dp,-1,sizeof(dp));
        return solve(0,amount,coins);
    }
};