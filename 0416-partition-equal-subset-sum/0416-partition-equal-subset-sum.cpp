class Solution {
public:
    bool solve(vector<int>& a,int n,int sum,vector<vector<int>>&dp)
    {
        if(sum==0)return true;
        
        if(n==0)return false;
        
        if(dp[n-1][sum]!=-1)
        {
            return dp[n-1][sum];
        }
        
        if(a[n-1]<=sum)
        {
            return dp[n-1][sum] = solve( a, n-1, sum-a[n-1], dp ) || solve( a, n-1, sum, dp);
        }
        else
        {
            return dp[n-1][sum]=solve( a, n-1, sum, dp);
        }
    }
    bool canPartition(vector<int>& a) {
        int total = accumulate(a.begin(),a.end(),0);
        if(total%2!=0)
        {
            return false;
        }
        int sum = total/2;
        int n = a.size();
        
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));        
        return solve(a,n,sum,dp);
    }
};