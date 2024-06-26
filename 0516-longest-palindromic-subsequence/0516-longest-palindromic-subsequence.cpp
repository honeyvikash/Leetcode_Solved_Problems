class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string text1=s;
        reverse(s.begin(),s.end());
        string text2=s;
        int n = text1.size();
        int m = text2.size();
        int dp[n+1][m+1];
        for(int i = 0; i<n+1; ++i)
        {
            for(int j = 0; j<m+1; ++j)
            {
                if(i*j == 0){
                    dp[i][j] = 0;
                }
            }
        }
        for(int i = 1; i<n+1; ++i)
        {
            for(int j = 1; j<m+1; ++j)
            {
                if(text1[i-1] == text2[j-1])
                {
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};