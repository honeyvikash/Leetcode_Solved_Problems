class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
        map<int,map<int,int>> m;
        for(int i=0;i<n;i++)
        {
            m[i][1]++;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j])
                {
                    dp[i] = max(dp[i],dp[j]+1);
                    m[i][dp[i]]+=m[j][dp[i]-1];
                }
            }
        }
        int maxi = 0;
        for(auto &i:dp)
        maxi = max(i,maxi);
        if(maxi==1)
        return n;
        int ans = 0;
        for(auto &i:m)
        {
            for(auto &j:i.second)
            {
                if(j.first==maxi)
                ans+=j.second;
            }
        }
        return ans;
    }
};