class Solution {
public:
    int dp[8][16385];
    int solve(vector<int>& nums,int stp,int mask)
    {
        int n = nums.size();
        if(stp>n/2)
        return 0;
        if(dp[stp][mask]!=-1)
        return dp[stp][mask];
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            if((mask>>i)&1)
            continue;
            for(int j=i+1;j<n;j++)
            {
                if((mask>>j)&1)
                continue;
                int newMask = (1<<i)|(1<<j)|mask;
                ans = max(ans,__gcd(nums[i],nums[j])*stp+
                solve(nums,stp+1,newMask));
            }
        }
        return dp[stp][mask] = ans;
    }
    int maxScore(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(nums,1,0);
    }
};