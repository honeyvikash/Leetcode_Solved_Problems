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
    
    int solveTab(vector<int>& sat)
    {
        int n=sat.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        
        for(int idx = n-1; idx>=0 ; idx--)
        {
            for(int time = idx ; time >=0 ; time--)
            {
                int in = sat[idx]*(time+1)+dp[idx+1][time+1];
                int ex = 0                +dp[idx+1][time];
                
                dp[idx][time] = max(in,ex);
            }
        }
        
        return dp[0][0];
    }
    int maxSatisfaction(vector<int>& sat) {
        // int n=sat.size();
        sort(sat.begin(),sat.end());
        // vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solveTab(sat);
    }
};