class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        // sum both and remove lcs
        int n = str1.size(),m = str2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));

        for(int i = 1 ; i <= n ; ++i)
            for(int j = 1 ; j <= m ; ++j)
                if(str1[i-1]==str2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1]+1;
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
        
        int i = n , j = m;
        string s = "";
        while(i>0 && j>0)
        {
            if(str1[i-1]==str2[j-1])
            {
                s+=str1[--i];
                j--;
            }
            else if(dp[i][j-1]<dp[i-1][j])
            {
                s+=str1[--i];
            }
            else
            {
                s+=str2[--j];
            }
        }

        for(;i>0;--i)
            s+=str1[i-1];
        for(;j>0;--j)
            s+=str2[j-1];
        reverse(s.begin(),s.end());
        return s;
    }
};