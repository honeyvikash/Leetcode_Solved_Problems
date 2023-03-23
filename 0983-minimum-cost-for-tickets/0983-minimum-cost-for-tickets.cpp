class Solution {
public:
    int solve(int n,vector<int>& days, vector<int>& costs,int idx,vector<int>&dp)
    {
        //base case
        if(idx>=n)
        {
            return 0;
        }
        if(dp[idx]!=-1)return dp[idx];
        
        //1day pass
        int option1 = costs[0]+solve(n,days,costs,idx+1,dp);
        
        int i;//7day
        for( i=idx;i<n && days[i]<days[idx]+7;i++);
        
        int option2 = costs[1]+solve(n,days,costs,i,dp);
        //30day
        for( i=idx;i<n && days[i]<days[idx]+30;i++);
        
        int option3 = costs[2]+solve(n,days,costs,i,dp);
        
        dp[idx]= min({option1,option2,option3});
        return  dp[idx];
        
        
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        vector<int>dp(n+1,-1);
        return solve(n,days,costs,0,dp);
    }
};