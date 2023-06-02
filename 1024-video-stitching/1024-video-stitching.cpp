class Solution {
public:
    
    int solveMem(int idx, int start,vector<vector<int>>& c, int time,vector<vector<int>>& dp)
    {
        if(start>=time)return 0;
        
        if(idx==c.size())
        {
            if(start>=time)
            {
                return 0;
            }
            return 1e9;
        }
        
        if(dp[idx][start] != -1)return dp[idx][start];
        
        if(c[idx][0]<=start)
        {
            return dp[idx][start]=min(1+solveMem(idx+1,c[idx][1],c,time,dp),solveMem(idx+1,start,c,time,dp));
        }
        
        return dp[idx][start]=1e9;
        
    }
    
    int videoStitching(vector<vector<int>>& c, int time) {
        sort(c.begin(),c.end());
        
        vector<vector<int>>dp(c.size(),vector<int>(time+1,-1));
        
        int res = solveMem(0,0,c,time,dp);
        if(res>=1e9)return -1;
        return res;
    }
};