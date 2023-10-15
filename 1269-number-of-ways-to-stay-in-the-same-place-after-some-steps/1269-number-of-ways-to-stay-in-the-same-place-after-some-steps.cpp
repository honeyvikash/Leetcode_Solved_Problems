int MOD=1e9+7;
class Solution {
public:
    int solve(int curr, int steps, int n, vector<vector<int>> &dp)
    {
        if(steps==0)
        {
            if(curr==0)
            {
                return 1;
            }
            return 0;
        }
        
        if(dp[curr][steps] != -1)
        {
            return dp[curr][steps];
        }

        int cnt=0;
        
        if(curr!=0)
        {
            cnt= (cnt+ solve(curr-1, steps-1, n, dp))%MOD;
        }
        
        if(curr!=n-1)
        {
            cnt= (cnt+ solve(curr+1, steps-1, n, dp))%MOD;
        }
        
        cnt= (cnt+ solve(curr, steps-1, n, dp))%MOD;

        return dp[curr][steps]= cnt;
    }
    int numWays(int steps, int arrLen) {
        vector<vector<int>> dp(steps+1, vector<int> (steps+1, -1));
        return solve(0, steps, arrLen, dp);
    }
};