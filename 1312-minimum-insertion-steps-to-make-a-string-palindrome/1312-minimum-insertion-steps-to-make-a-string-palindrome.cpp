class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        string tmp = s;
        reverse(tmp.begin(),tmp.end());
        int dp[n+1][n+1];
        for(int i=0;i<n+1;i++)
        {
            dp[i][0] = 0;
        }
        for(int i=0;i<n+1;i++)
        {
            dp[0][i] = 0;
        }
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<n+1;j++)
            {
                if(s[i-1]==tmp[j-1])
                {
                    dp[i][j] = dp[i-1][j-1]+1;
                }
                else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        
        return n-dp[n][n];
    }
};