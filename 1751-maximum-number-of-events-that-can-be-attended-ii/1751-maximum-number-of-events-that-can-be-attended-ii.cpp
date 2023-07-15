class Solution {
public:
    int bs(vector<vector<int>>& e,int val)
    {
        int l = 0,r = e.size()-1;
        int ans = e.size();
        while(l<=r)
        {
            int mid = l+(r-l)/2;
            if(e[mid][0]>val)
            {
                ans = mid;
                r = mid-1;
            }
            else
            l = mid+1;
        }
        return ans;
    }
    int solve(int idx,vector<vector<int>>& e,vector<vector<int>>& dp,int k)
    {
        if(k==0 || idx>=e.size())
            return 0;
        if(dp[idx][k]!=-1)
            return dp[idx][k];
        int en = e[idx][1];
        int it = bs(e,en);
        int take = e[idx][2]+solve(it,e,dp,k-1);
        int notTake = solve(idx+1,e,dp,k);
        return dp[idx][k] = max(take,notTake);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(),events.end());
        int n = events.size();
        vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
        return solve(0,events,dp,k);
    }
};