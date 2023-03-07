class Solution {
public:
    #define all(a) (a).begin(), (a).end()


    int findTargetSumWays(vector<int>& a, int t) {
        int sum=accumulate(all(a),0);
        int req=(sum+t)/2;
        if(t>sum || (sum-t)%2 || req<0)return 0;
        int n=a.size();
        vector<vector<int>>dp(n+1,vector<int>(req+1,0));
        
            for(int i=0;i<n+1;i++)
            {
                dp[i][0]=1;
            }
        for(int i=1;i<n+1;i++)
        {
            //yhi to catch hai BCCCC.....we start from j=0 instead of j=1
            for(int j=0;j<req+1;j++)
            {
                if(a[i-1]<=j)
                {
                    dp[i][j]=dp[i-1][j-a[i-1]] + dp[i-1][j];
                }
                else
                {
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][req];
    }
};