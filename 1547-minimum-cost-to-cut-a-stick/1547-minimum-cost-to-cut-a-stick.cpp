class Solution {
public:
    int dp[105][105];
    int solve(int l,int r,vector<int>& cuts)
    {
        if(r-l<=1)
        return 0;
        if(dp[l][r]!=-1)
        return dp[l][r];
        int ans = INT_MAX;
        for(int i=l+1;i<r;i++)
        {
            ans = min(ans,cuts[r]-cuts[l]+solve(l,i,cuts)+
            solve(i,r,cuts));
        }
        return dp[l][r] = ans;
    }
    int minCost(int n, vector<int>& cuts) {
        memset(dp,-1,sizeof(dp));
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        return solve(0,cuts.size()-1,cuts);
    }
};