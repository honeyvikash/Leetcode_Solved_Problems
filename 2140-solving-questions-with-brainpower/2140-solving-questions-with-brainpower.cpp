class Solution {
public:
    #define ll long long
    ll dp[100001];
    ll solve(int idx,vector<vector<int>>& q)
    {
        if(idx>=q.size())
        return 0;
        if(dp[idx]!=-1)
        return dp[idx];
        ll take = q[idx][0]+solve(idx+q[idx][1]+1,q);
        ll notTake = solve(idx+1,q);
        return dp[idx] = max(take,notTake);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        memset(dp,-1,sizeof(dp));
        return solve(0,questions);
    }
};