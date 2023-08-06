class Solution {
public:
    const int m = 1e9+7;
    int solve(int song,int usong,int n,int goal,int k,vector<vector<int>>&dp)
    {
        if(song==goal)
        {
            return n==usong;
        }
        if(dp[song][usong]!=-1)return dp[song][usong];
        int take = ((1ll)*((n-usong)%m)*solve(song+1,usong+1,n,goal,k,dp))%m;
        int nottake=((1ll)*((max((usong-k),0))%m)*solve(song+1,usong,n,goal,k,dp))%m;
        
        return dp[song][usong]=(take+nottake);
    }
    int numMusicPlaylists(int n, int goal, int k) {
        vector<vector<int>>dp(goal+1,vector<int>(goal+1,-1));
        return solve(0,0,n,goal,k,dp);
    }
};