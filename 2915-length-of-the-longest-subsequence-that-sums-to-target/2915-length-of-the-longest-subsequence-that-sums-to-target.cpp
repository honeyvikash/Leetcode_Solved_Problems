class Solution {
public:
    int solve(int idx,vector<int> &a,int target,vector<vector<int>> &dp)
    {
        if(target==0)
            return 0;
        if(idx>=a.size())
            return INT_MIN;
        if(dp[idx][target]!=INT_MIN)
            return dp[idx][target];
        int tak = INT_MIN,notTak = INT_MIN;
        if(a[idx]<=target)
        {
            tak = 1+solve(idx+1,a,target-a[idx],dp);
        }
        notTak = solve(idx+1,a,target,dp);
        return dp[idx][target] = max(tak,notTak);
    }
    int lengthOfLongestSubsequence(vector<int>& a, int target) {
        int n = a.size();
        vector<vector<int>> dp(n+1,vector<int>(target+1,INT_MIN));
        int ans = solve(0,a,target,dp);
        if(ans<=0) return -1;
        return ans;
    }
};