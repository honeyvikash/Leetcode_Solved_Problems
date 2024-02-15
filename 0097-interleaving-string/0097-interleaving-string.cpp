class Solution {
public:
    int dp[101][101];
    int solve(int i,int j,string& s1,string& s2,string& s3)
    {
        if(i==s1.size() && j==s2.size())
            return true;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(i<s1.size() && j<s2.size() && s1[i]==s3[i+j] && s2[j]==s3[i+j])
        {
            int tak1 = solve(i+1,j,s1,s2,s3);
            int tak2 = solve(i,j+1,s1,s2,s3);
            return dp[i][j] = tak1 || tak2;
        }
        if(i<s1.size() && s1[i]==s3[i+j])
        {
            return dp[i][j] = solve(i+1,j,s1,s2,s3);
        }
        if(j<s2.size() && s2[j]==s3[i+j])
        {
            return dp[i][j] = solve(i,j+1,s1,s2,s3);
        }
        return dp[i][j] = false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size())
        return false;
        memset(dp,-1,sizeof(dp));
        return solve(0,0,s1,s2,s3);
    }
};