class Solution {
public:
    int solve(int i,int j,string &s1,string &s2,vector<vector<int>> &dp)
    {
        if(i<0)
        {
            int ans = 0;
            for (int k = 0; k <= j; k++)
            {
                ans += (int)s2[k];
            }
            return ans;
        }
        if(j<0)
        {
            int ans = 0;
            for(int k=0;k<=i;k++)
            {
                ans+=(int)s1[k];
            }
            return ans;
        }
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(s1[i]==s2[j])
        {
            return dp[i][j]=solve(i-1,j-1,s1,s2,dp);
        }
        else
        {
            return dp[i][j]=min((int)s1[i] + solve(i - 1, j, s1, s2,dp), (int)s2[j] + solve(i, j - 1, s1, s2,dp));
        }
    }
    int minimumDeleteSum(string s1, string s2) {
        
        int n1 = s1.size();
        int n2 = s2.size();
        // vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1));
        // return solve(n1-1,n2-1,s1,s2,dp);
        
        int dp[n1+1][n2+1];
        
        for(int i=0;i<n1+1;i++)
            dp[i][0] = 0;
        for(int i=0;i<n2+1;i++)
            dp[0][i] = 0;
        for(int i=1;i<n1+1;i++)
        {
            for(int j=1;j<n2+1;j++)
            {
                if(s1[i-1]==s2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1]+s1[i-1];
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        int sum1=0,sum2=0;
        for(auto &i:s1)
            sum1+=(i);
        for(auto &i:s2)
            sum2+=(i);
        return (sum1-dp[n1][n2])+(sum2-dp[n1][n2]);
    }
};