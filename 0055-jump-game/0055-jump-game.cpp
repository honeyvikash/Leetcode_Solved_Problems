class Solution {
public:
    bool solve(int i,vector<int>& a,int n,vector<int>&dp)
    {
        if(i==n-1)return 1;
        if(i>=n)return 0;
        if(dp[i]!=-1)return dp[i];
        dp[i]=0;
        for(int jump=1;jump<=a[i];jump++)
        {
            dp[i] |= solve(i+jump,a,n,dp);
        }
        return dp[i];
    }
    bool canJump(vector<int>& a) {
        // Greddy Approach
        int n= a.size();
        int maxIdx=0;
        for(int i=0;i<=maxIdx;i++)
        {
            maxIdx=max(maxIdx,a[i]+i);
            if(maxIdx>=n-1)return 1;
        }
        return 0;
        // vector<int>dp(n+1,-1);
        // return solve(0,a,a.size(),dp);
    }
};