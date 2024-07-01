class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        for(auto &a:nums)
            a%=k;
        int ans = 0;
        map<int,int> mp;
        for(auto&a:nums)
            mp[a]++,
            ans = max(ans,mp[a]);
        
        int n = nums.size();
        vector<vector<int>> dp(k,vector<int>(k,1));
        
        for(int i = 0 ; i < n ; ++i)
        {
            for(int j = 0 ; j < i ; ++j)
            {
                if(nums[j]!=nums[i])
                    dp[nums[i]][nums[j]] = max(dp[nums[i]][nums[j]],1 + dp[nums[j]][nums[i]]);
                ans = max(ans,dp[nums[i]][nums[j]]);
            }
        }
        return ans;
    }
};