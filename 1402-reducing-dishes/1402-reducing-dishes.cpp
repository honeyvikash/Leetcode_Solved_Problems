class Solution {
public:
    int solve(vector<int>& sat,int idx,int time,vector<vector<int>>&dp)
    {
        if(idx==sat.size())return 0;
        
        if(dp[idx][time]!=-1)return dp[idx][time];
        
        int include=sat[idx]*(time+1)+solve(sat,idx+1,time+1,dp);
        int exclude= 0+ solve(sat,idx+1,time,dp);
        
        dp[idx][time] = max(include,exclude);
        return dp[idx][time];
    }
    int maxSatisfaction(vector<int>& sat) {
        int n=sat.size();
        sort(sat.begin(),sat.end());
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(sat,0,0,dp);
    }
};