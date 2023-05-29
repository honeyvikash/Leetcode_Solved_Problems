class Solution {
    #define ll long long 
public:
    int solveMem(vector<int>& nums, int tar,vector<int>& dp)
    {
        if(tar<0)return 0;
        if(tar==0)return 1;
        
        if(dp[tar] != -1)return dp[tar];
        
        int ans = 0;
        for(int i=0;i<nums.size();i++)
        {
            ans+=solveMem(nums,tar-nums[i],dp);
        }
        return dp[tar]=ans;
    }
    int solve(vector<int>& nums, int tar)
    {
        if(tar<0)return 0;
        if(tar==0)return 1;
        
        int ans = 0;
        for(int i=0;i<nums.size();i++)
        {
            ans+=solve(nums,tar-nums[i]);
        }
        return ans;
    }
    
    int solveTab(vector<int>& nums, int& tar)
    {
        vector<ll>dp(tar+1,0);
        dp[0]=1;
        
        for(int i=1;i<=tar;i++)
        {
            for(int j=0;j<nums.size();j++)
            {
                if(i-nums[j]>=0)
                {
                    dp[i] += dp[i-nums[j]];
                }
                if (dp[i] > INT_MAX) break; //
            }
        }
        return dp[tar];
    }
    
    int combinationSum4(vector<int>& nums, int tar) {
        // vector<int>dp(tar+1,-1);
        // return solveMem(nums,tar,dp);
        return solveTab(nums,tar);
    }
};