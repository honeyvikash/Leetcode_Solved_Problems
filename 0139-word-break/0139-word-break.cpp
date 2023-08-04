class Solution {
public:
    bool solve(int idx,string s,unordered_map<string,int>&m)
    {
        if(idx==s.size())return 1;
        
        string tmp="";
        for(int i=idx; i<s.size(); i++)
        {
            tmp+=s[i];
            if(m.find(tmp)!=m.end())
            {
                if(solve(i+1,s,m)==1)
                {
                    return 1;
                }
            }
        }
        
        return 0;
    }
    bool solveM(int idx,string s,unordered_map<string,int>&m,vector<int>&dp)
    {
        if(idx==s.size())return 1;
        if(dp[idx]!=-1)return dp[idx];
        
        string tmp="";
        for(int i=idx; i<s.size(); i++)
        {
            tmp+=s[i];
            if(m.find(tmp)!=m.end())
            {
                if(solveM(i+1,s,m,dp)==1)
                {
                    dp[idx]=1;
                    return dp[idx];
                }
            }
        }
        
        return dp[idx]=0;
    }
    bool wordBreak(string s, vector<string>& wd) {
        unordered_map<string,int>m;
        for(auto x:wd)m[x]++;
        int n = s.size();
        // return solve(0,s,m);
        vector<int>dp(n+1,-1);
        return solveM(0,s,m,dp);
        
    }
};