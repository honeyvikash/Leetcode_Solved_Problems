class Solution {
public:
    int solve(int i, int j,string w1,string w2,vector<vector<int>>&dp)
    {
        if(i==w1.size())
        {
            return w2.size()-j;
        }
        if(j==w2.size())
        {
            return w1.size()-i;
        }
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        int temp = 0;
        if(w1[i]==w2[j])
        {
            return solve(i+1,j+1,w1,w2,dp);
        }
        
        else 
        {
            int insert = 1+solve(i+1,j,w1,w2,dp);
            int delet = 1+solve(i,j+1,w1,w2,dp);
            int replace = 1+solve(i+1,j+1,w1,w2,dp);
            temp = min({insert,delet,replace});
        }
        
        dp[i][j]=temp;
        return dp[i][j];
    }
    
    int minDistance(string w1, string w2) {
        int n = w1.size(),m=w2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int ans = 0;
        ans = solve(0,0,w1,w2,dp);
        return ans;
    }
};