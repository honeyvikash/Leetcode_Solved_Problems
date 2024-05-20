class Solution {
    int solve(vector<int> &prices,int ind,int buy,vector<vector<int>> &dp){ 
    if(ind==prices.size())return 0;
    int profit=0;
    if(dp[ind][buy]!=-1)return dp[ind][buy];
    if(buy)
    {
        //buy or not buy
        int take=-prices[ind]+solve(prices,ind+1,0,dp);
        int notTake=solve(prices,ind+1,1,dp);
        profit=max(take,notTake);
    }
    else
    {
        //sell or not sell
        int sell=prices[ind]+solve(prices,ind+1,1,dp);
        int notSell=solve(prices,ind+1,0,dp);
        profit=max(sell,notSell);
    }
    return dp[ind][buy]=profit;
    }
    public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int> (2,-1));
        return solve(prices,0,1,dp);
    }
};