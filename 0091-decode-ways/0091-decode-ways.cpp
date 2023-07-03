class Solution {
public:
    int solveMem(int idx, string s, vector<int>& dp)
    {
        if(idx==s.size())return 1;
        
        if(dp[idx]!=-1)return dp[idx];
        
        int x1 = 0;
        if(s[idx]!='0')x1 = solveMem(idx+1,s,dp);
        
        int x2 = 0;
        if(idx<s.size()-1 and s[idx]!='0')
        {
            int res = (s[idx]-'0')*10+(s[idx+1]-'0');
            if(res>=0 and res<=26)
            {
                x2 = solveMem(idx+2,s,dp);
            }
        }
        dp[idx] = x1+x2;
        return dp[idx];
    }
    int numDecodings(string s) {
        int n = s.size();
        vector<int>dp(n+1,-1);
        return solveMem(0,s,dp);
    }
};