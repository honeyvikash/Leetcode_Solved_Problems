class Solution {
public:
    int dp[21][10001];
    int solve(int idx,vector<int>& rods,int diff)
    {
        if(idx==rods.size())
        {
            if(diff==0)
            return 0;
            return INT_MIN;
        }
        
        if(dp[idx][diff+5000]!=-1)
            return dp[idx][diff+5000];
        
        int t1 = solve(idx+1,rods,diff);
        
        int t2 = rods[idx]+solve(idx+1,rods,diff+rods[idx]);
        
        int t3 = solve(idx+1,rods,diff-rods[idx]);
        
        return dp[idx][diff+5000] = max({t1,t2,t3});
    }
    int tallestBillboard(vector<int>& rods) {
        
        memset(dp,-1,sizeof(dp));
        return solve(0,rods,0);
    }
};