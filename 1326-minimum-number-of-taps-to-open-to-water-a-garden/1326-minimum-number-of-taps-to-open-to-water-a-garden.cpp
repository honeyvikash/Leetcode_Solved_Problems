class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<vector<int>> rang;
        for(int i=0;i<ranges.size();i++)
        {
            int st = i-ranges[i];
            int en = i+ranges[i];
            rang.push_back({st,en});
        }
        sort(rang.begin(),rang.end());
        vector<int> dp(n+2,n+1);
        dp[0] = 0;
        for(int i=1;i<=n;i++)
        {
            for(auto &j:rang)
            {
                if(j[0]<=i && j[1]>=i)
                {
                    if(j[0]>=0)
                    dp[i] = min(dp[i],dp[j[0]]+1);
                    else
                    dp[i] = min(dp[i],dp[0]+1);
                }
            }
            if(dp[i]>=n+1)
            return -1;
        }
        return dp[n];
    }
};