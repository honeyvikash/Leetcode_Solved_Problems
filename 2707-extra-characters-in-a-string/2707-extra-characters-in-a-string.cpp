class Solution {
public:
    unordered_map<string,int>mp;
    vector<vector<int>>dp;
    int dfs(int i,int j,string &s)
    {
        if(i>j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        
        string tmp = s.substr(i,(j-i+1));
        
        if(mp[tmp]==1) return (j-i+1);
        
        int ans =0;
        for(int p=i;p<j;p++)
        {
            ans = max(ans,dfs(i,p,s)+dfs(p+1,j,s));
        }
        
        return dp[i][j] = ans;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        for(auto it : dictionary)
            mp[it] = 1;
        
        dp = vector<vector<int>>(n, vector<int>(n, -1));
        return s.size() - dfs(0, n-1, s);
    }
};