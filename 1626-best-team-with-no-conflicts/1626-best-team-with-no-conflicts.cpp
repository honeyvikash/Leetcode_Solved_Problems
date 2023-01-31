class Solution {
public: 
    int ans = INT_MIN;
    int solve(vector<pair<int,int>>&v)
    {
        int n = v.size();
        vector<int>dp(n);
        for(int i = 0 ; i < n ; i++)
        {
            dp[i] = v[i].second;
            ans = max(ans,dp[i]);
        }
        for(int i =0 ; i < n ; i++)
        {
            for(int j = i-1 ; j >= 0 ; j--)
            {
                if(v[i].second >= v[j].second)
                {
                    dp[i] = max(dp[i],v[i].second+dp[j]);
                }
            }
            ans = max(ans,dp[i]);
        }
        return ans;
    }
    int bestTeamScore(vector<int>& s, vector<int>& a) {
        vector<pair<int,int>>v;
        
        int n = a.size();
        for(int i=0 ; i < n ; i++)
        {
            v.push_back({a[i],s[i]});
        }
        sort(v.begin(),v.end());
        return solve(v);
    }
};