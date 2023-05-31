class Solution {
public:
    int solve(int idx,string s,unordered_map<string,int>&m, vector<int>& dp)
    {
        if(idx>=s.size())return 0;
        
        if(dp[idx]!=-1)return dp[idx];
        
        int ans = 1 + solve(idx+1,s,m,dp);
        
        for(int i=1; i+idx<=s.size();i++)
        {
            string tmp = s.substr(idx,i);
            if(m.find(tmp)!=m.end())
            {
                ans = min(ans,solve(idx+i,s,m,dp));
            }
        }
        return dp[idx]=ans;
    }
    int minExtraChar(string s, vector<string>& dic) {
        vector<int>dp(s.size()+1,-1);
        unordered_map<string,int>m;
        for(auto x:dic)
        {
            m[x]++;
        }
        return solve(0,s,m,dp);
    }
};