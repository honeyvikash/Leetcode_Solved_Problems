class Solution {
public:
    int tabuation(vector<int>& nums, int target)
    {
        vector<long long>dp(1001,0);
        dp[0]=1;
        
        for(int i=1;i<=target;i++)
        {
            for(int j=0;j<nums.size() ;j++)
            {
                if(i-nums[j]>=0)
                {
                    dp[i]+=dp[i-nums[j]];    
                    if(dp[i]>=INT_MAX)
                    {
                        dp[i] = INT_MAX;
                        break;
                    }
                }
            }
        }
        return dp[target];
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        return tabuation(nums,target);
    }
};