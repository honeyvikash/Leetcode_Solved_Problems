class Solution {
public:
    int dp[21][21][2];
    int solve(int i,int j,vector<int>& nums,int flg)
    {
        if(i>j)
            return 0;
        if(dp[i][j][flg]!=-1)
            return dp[i][j][flg];
        if(flg)
        {
            int tak1 = nums[i]+solve(i+1,j,nums,0);
            int tak2 = nums[j]+solve(i,j-1,nums,0);
            return dp[i][j][flg] = max(tak1,tak2);
        }
        else
        {
            int tak1 = solve(i+1,j,nums,1)-nums[i];
            int tak2 = solve(i,j-1,nums,1)-nums[j];
            return dp[i][j][flg] = min(tak1,tak2);
        }
    }
    
    int solve2(vector<int>&v,int i,int j,vector<vector<int>>&dp)
    {
        if(i>j)return 0;
        if(i==j) return v[i];
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        int playeronescore = 0;
    
        playeronescore = max(v[i]+min(solve2(v,i+2,j,dp),solve2(v,i+1,j-1,dp))
                            ,v[j]+min(solve2(v,i,j-2,dp),solve2(v,i+1,j-1,dp)));
        
        return dp[i][j]=playeronescore;
    }
    bool PredictTheWinner(vector<int>& a) {
        
        long long total = accumulate(a.begin(),a.end(),0ll);
        int n = a.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int f = solve2(a,0,n-1,dp);
        return f>=total-f;
        
        // memset(dp,-1,sizeof(dp));
        // int n = a.size();
        // int ans = solve(0,n-1,a,1);
        // if(ans>=0)
        //     return true;
        // return false;
        
        
        
    }
};