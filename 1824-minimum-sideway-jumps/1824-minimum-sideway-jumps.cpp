class Solution {
public:
    int solve(vector<int>& obs, int currlane, int currpos)
    {
        int n = obs.size()-1;//as given of size(n+1)
        
        if(currpos == n) return 0;
        
        if(obs[currpos+1] != currlane)
        {
            return solve(obs,currlane,currpos+1);
        }
        
        else
        {
            //now its a time for sideways jump
            int ans = INT_MAX;
            for(int i=1;i<=3;i++)
            {
                if(currlane != i && obs[currpos] != i)
                {
                    ans = min(ans,1+solve(obs,i,currpos));
                }
            }
            return ans;
        }
    }
    
    
    int solveMem(vector<int>& obs, int currlane, int currpos,vector<vector<int>>&dp)
    {
        int n = obs.size()-1;//as given of size(n+1)
        
        if(currpos == n) return 0;
        
        if(dp[currlane][currpos] != -1)return dp[currlane][currpos];
        
        if(obs[currpos+1] != currlane)
        {
            return solveMem(obs,currlane,currpos+1,dp);
        }
        
        else
        {
            //now its a time for sideways jump
            int ans = INT_MAX;
            for(int i=1;i<=3;i++)
            {
                if(currlane != i && obs[currpos] != i)
                {
                    ans = min(ans,1+solveMem(obs,i,currpos,dp));
                }
            }
            dp[currlane][currpos]=ans;
            
            return dp[currlane][currpos];
        }
    }
    int minSideJumps(vector<int>& obstacles) {
        // return solve(obstacles,2,0);
        int n = obstacles.size()-1;
        vector<vector<int>>dp(3+1,vector<int>(n+1,-1));
        return solveMem(obstacles,2,0,dp);
    }
};